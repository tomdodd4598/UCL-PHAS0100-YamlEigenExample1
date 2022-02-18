#include <iostream>
#include <Eigen/Dense>

int main() {

    Eigen::Matrix2d m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    std::cout << "m(2, 2) \n" << m << std::endl;

    Eigen::Vector3d vr(3);
    vr << 1, 0, 1;
    Eigen::Matrix3d corners(3, 3);
    corners << vr * vr.transpose();
    std::cout << "corners matrix:\n"
        << corners << std::endl;

    Eigen::MatrixXd X = Eigen::MatrixXd::Random(5, 5);
    std::cout << "A random matrix X: \n" << X
        << "\nIts inverse X^-1: \n" << X.inverse()
        << "\nIs X * X^-1 == I? "
        << std::boolalpha 
        << (X * X.inverse()).isApprox(Eigen::MatrixXd::Identity(5, 5)) 
        << std::endl;
}
