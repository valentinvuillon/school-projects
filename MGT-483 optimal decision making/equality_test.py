import numpy as np
import matplotlib.pyplot as plt
import os

# making sure the code is run with a working directory where the file '100x100_markings.npy' is
script_dir = os.path.dirname(os.path.abspath(__file__))
os.chdir(script_dir)

matching_matrix_bland = np.load('matching_matrix_bland.npy')
matching_matrix_dantzig = np.load('matching_matrix_dantzig.npy')

if np.array_equal(matching_matrix_bland, matching_matrix_dantzig):
    print("They are the same matrices")
else:
    print("The matrices are different")
