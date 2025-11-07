import numpy as np
import matplotlib.pyplot as plt
import cvxpy as cp
import os


def create_board(rows, cols, markings):
    board = np.zeros((rows, cols), dtype=int)
    for row, col in markings:
        board[row, col] = 1
    return board


def create_incidence_matrix(rows, cols, markings):
    incidence_matrix = np.zeros((rows + cols, len(markings)), dtype=int)
    for j, (row, col) in enumerate(markings):
        incidence_matrix[row, j] = 1
        incidence_matrix[col + rows, j] = 1
    return incidence_matrix


def build_matching_matrix(rows, cols, markings, match_values, tol=1e-8):
    matrix = np.zeros((rows, cols), dtype=int)
    for j, (row, col) in enumerate(markings):
        if match_values[j] > tol:
            matrix[row, col] = 1
    return matrix


def build_vertexcover_matrix(rows, cols, cover_values, tol=1e-8):
    matrix = np.zeros((rows, cols), dtype=int)
    # cover_values length = rows + cols
    for i in range(rows):
        if cover_values[i] > tol:
            matrix[i, :] = 1
    for j in range(cols):
        if cover_values[rows + j] > tol:
            matrix[:, j] = 1
    return matrix


def make_plots(rows, cols, markings, marker_sizes):
    # Plot board with marked tiles (in red)
    board = create_board(rows, cols, markings)
    plt.spy(board, markersize=marker_sizes[0], color='red')

    # Define incidence matrix
    A = create_incidence_matrix(rows, cols, markings)

    # maximum matching via LP: maximize sum x_j subject to A x <= 1, x >= 0
    m = A.shape[1]
    x = cp.Variable(m, nonneg=True)
    constraints_match = [A @ x <= np.ones(A.shape[0])]
    obj_match = cp.Maximize(cp.sum(x))
    prob_match = cp.Problem(obj_match, constraints_match)
    max_match_val = prob_match.solve(solver=cp.GLPK, glpk={'msg_lev': 'GLP_MSG_OFF'})
    print("Optimal matching value:", max_match_val)
    matching_vals = x.value
    matching_matrix = build_matching_matrix(rows, cols, markings, matching_vals)
    plt.spy(matching_matrix, markersize=marker_sizes[1], color='yellow')

    # minimum vertex cover via LP: minimize sum y_i subject to A^T y >= 1, y >= 0
    n_vertices = A.shape[0]
    y = cp.Variable(n_vertices, nonneg=True)
    constraints_cover = [A.T @ y >= np.ones(A.shape[1])]
    obj_cover = cp.Minimize(cp.sum(y))
    prob_cover = cp.Problem(obj_cover, constraints_cover)
    min_cover_val = prob_cover.solve(solver=cp.GLPK, glpk={'msg_lev': 'GLP_MSG_OFF'})
    print("Optimal vertex cover value:", min_cover_val)
    cover_vals = y.value
    vertexcover_matrix = build_vertexcover_matrix(rows, cols, cover_vals)
    plt.spy(vertexcover_matrix, markersize=marker_sizes[2], color='blue')


def main():
    # making sure the code is run with a working directory where the file '100x100_markings.npy' is
    script_dir = os.path.dirname(os.path.abspath(__file__))
    os.chdir(script_dir)

    # Figure 1 board
    rows, cols = 6, 6
    markings = [(0, 1), (2, 0), (2, 3), (2, 5), (3, 1), (4, 1), (4, 2), (4, 4), (5, 0)]
    marker_sizes = [20, 10, 5]
    plt.figure()
    make_plots(rows, cols, markings, marker_sizes)
    plt.savefig("cvxpy_6x6.pdf", bbox_inches='tight')
    plt.show()

    # Large 100 x 100 board
    rows, cols = 100, 100
    markings = np.load('100x100_markings.npy')
    marker_sizes = [4, 2, 1]
    plt.figure(figsize=(8, 8))
    make_plots(rows, cols, markings, marker_sizes)
    plt.savefig("cvxpy_100x100.pdf", bbox_inches='tight')
    plt.show()


if __name__ == '__main__':
    main()
