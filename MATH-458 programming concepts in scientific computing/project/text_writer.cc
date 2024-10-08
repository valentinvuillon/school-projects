#include "text_writer.hh"
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>

/* -------------------------------------------------------------------------- */

void TextWriter::write(DataOut DataOut_){

    std::vector<double> t=DataOut_.Gett();
    Eigen::MatrixXd y=DataOut_.Gety();
    int Dimension = y.rows();

    size_t N(t.size());
    std::ofstream write_output("output.txt");
    assert(write_output.is_open());

    for(int i=0; i<N ;i++)
    {
        write_output<<std::left <<std::setw(15)<<t[i];
        for (int j = 0; j < Dimension; ++j)
        {
            write_output<<std::left<<std::setw(15)<< y(j,i);
        }
        write_output<<std::endl;
    }

    write_output.close();


}



/* --------------------------------------------------------------------------- */


