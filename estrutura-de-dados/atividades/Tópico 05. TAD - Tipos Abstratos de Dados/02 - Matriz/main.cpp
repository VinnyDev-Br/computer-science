// ------------------------------------------------
// ESTE ARQUIVO JA ESTA FINALIZADO, NAO MEXA NELE
// ------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include "Matrix.h"

using namespace std;

int main()
{
    vector<Matrix*> matrices;

    string command;

    while (cin >> command) {

        // ----------------------------------------
        // creatematrix
        // ----------------------------------------
        if (command == "creatematrix") {

            int rows, columns;

            cin >> rows >> columns;

            Matrix* matrix = new Matrix(rows, columns);

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {

                    int value;
                    cin >> value;

                    matrix->set_value(i, j, value);
                }
            }

            matrices.push_back(matrix);
        }

        // ----------------------------------------
        // nlinhas
        // ----------------------------------------
        else if (command == "nlinhas") {

            int k;
            cin >> k;

            cout << "linhas: "
                 << matrices[k]->get_rows()
                 << endl;
        }

        // ----------------------------------------
        // ncolunas
        // ----------------------------------------
        else if (command == "ncolunas") {

            int k;
            cin >> k;

            cout << "colunas: "
                 << matrices[k]->get_columns()
                 << endl;
        }

        // ----------------------------------------
        // getvalor
        // ----------------------------------------
        else if (command == "getvalor") {

            int i, j, k;

            cin >> i >> j >> k;

            cout << matrices[k]->get_value(i, j)
                 << endl;
        }

        // ----------------------------------------
        // printmatrix
        // ----------------------------------------
        else if (command == "printmatrix") {

            int k;

            cin >> k;

            matrices[k]->print();
        }

        // ----------------------------------------
        // sum
        // ----------------------------------------
        else if (command == "sum") {

            int p, q;

            cin >> p >> q;

            Matrix& a = *matrices[p];
            Matrix& b = *matrices[q];

            /*
             * A matriz resultado é criada mesmo que
             * a soma seja impossível.
             *
             * Isso é necessário porque ela também deve
             * ser liberada no comando exit.
             */
            Matrix* c = new Matrix(a.get_rows(), a.get_columns());

            if (a.get_rows() != b.get_rows() ||
                a.get_columns() != b.get_columns())
            {
                cout << "nao foi possivel somar" << endl;
            }
            else
            {
                matrix_sum(a, b, *c);
                c->print();
            }

            matrices.push_back(c);
        }

        // ----------------------------------------
        // multiply
        // ----------------------------------------
        else if (command == "multiply") {

            int p, q;

            cin >> p >> q;

            Matrix& a = *matrices[p];
            Matrix& b = *matrices[q];

            /*
             * A matriz resultado possui:
             *
             * número de linhas de a
             * número de colunas de b
             *
             * Ela também é criada quando a multiplicação
             * é impossível, mas nesse caso não é impressa.
             */
            Matrix* c = new Matrix(a.get_rows(), b.get_columns());

            if (a.get_columns() != b.get_rows())
            {
                cout << "nao foi possivel multiplicar" << endl;
            }
            else
            {
                matrix_multiply(a, b, *c);
                c->print();
            }

            matrices.push_back(c);
        }

        // ----------------------------------------
        // exit
        // ----------------------------------------
        else if (command == "exit") {

            for (Matrix* matrix : matrices) {

                delete matrix;

                cout << "matriz liberada" << endl;
            }

            return 0;
        }
    }

    return 0;
}