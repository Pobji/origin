#include <iostream>
#include <fstream>

int main()
{
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    if (fin.is_open())
    {
        int Nk = 0;
        fin >> Nk;
        int* N = new int[Nk];
        for (int i = 0; i < Nk; i++)
        {
            if (i + 1 < Nk) fin >> N[i + 1];
            else fin >> N[0];
        }
        int Mk = 0;
        fin >> Mk;
        int* M = new int[Mk];
        for (int i = 0; i < Mk; i++)
        {
            if (i == 0) fin >> M[Mk - 1];
            else fin >> M[i - 1];
        }
        fout << Mk << std::endl;
        for (int i = 0; i < Mk; i++)
        {
            fout << M[i];
            if (i < Mk - 1) fout << " ";
            else fout << std::endl;
        }
        fout << Nk << std::endl;
        for (int i = 0; i < Nk; i++)
        {
            fout << N[i];
            if (i < Nk - 1) fout << " ";
        }
        fin.close();
        fout.close();
        delete[] N;
        delete[] M;
        std::cout << std::endl;
    }
    else std::cout << "File not found!";
}