#define msize 1000 // 操作字符串最大长度
#include <iostream>
#include "notepad.c++"
#include "help.c++"
#include <exception>
using namespace std;
int main()
{
    notepad h;
    try
    {
        h.read((char *)"help.c++");
    }
    catch (exception e)
    {
        cout << "Chm lost!Please run with the resource!";
        return 0;
    }
    h.print(2, 11);
    char c;
    int no, ni;
    notepad n;
    cout << "(ZET)";
    while ((c = cin.get()) != 'q')
    {
        char i = cin.get();

        char cmd[50];
        if (i != ' ' && i != '\n')
        {
            cout << "Invalid command,type 'h' for help." << endl;
            cin.getline(cmd, 50);
            cout << "(ZET)";
            continue;
        }

        try
        {
            switch (c)
            {
            case 'K':
            {
                char c[msize];
                int x[2] = {1, 0};
                cin >> no >> c;
                if (cin.fail())
                    throw 0;
                cin.get();
                if (n.KMP(no, c, x))
                    cout << x[0] << ',' << x[1];
                else
                    cout << 0;
                cout << endl;
            }
            break;
            case 'r':
                cin.getline(cmd, 50);
                n.read(cmd);
                break;
            case 'k':
                cout << n.kuohao();
                cout << endl;
                break;
            case 'h':
                h.print(12, 20);
                break;
            case 'w':
                cin.getline(cmd, 50);
                n.write(cmd);
                break;
            case 'p':
                cin >> no;
                if (cin.get() == ' ')
                {
                    cin >> ni;
                    n.print(no, ni);
                    cin.get();
                }
                else
                    n.print(no);
                break;
            case 'i':
                cin >> no;
                if (cin.get() == ' ')
                {
                    char c[msize];
                    cin >> ni >> c;
                    n.insert(no, ni, c);
                    cin.get();
                }
                else
                    n.insert(no);
                break;
            case 'd':
                cin >> no;
                if (no == 0)
                {
                    cin.get();
                    cin >> no;
                    if (cin.get() == ' ')
                    {
                        cin >> ni;
                        n.delr(no, ni);
                        cin.get();
                    }
                    else
                        n.delr(no);
                }
                else
                {
                    cin.get();
                    cin >> no >> ni;
                    if (cin.get() == ' ')
                    {
                        int k;
                        cin >> k;
                        n.del(no, ni, k);
                        cin.get();
                    }
                    n.del(no, ni);
                }
                break;
            default:
                cout << "Invalid command,type in 'h' for help." << endl;
                cin.getline(cmd, 50);
                break;
            }
        }
        catch (...)
        {
            cin.clear();
            cout << "Fatal error!Wrong syntax!Please read file in and try again!" << endl;
            cin.getline(cmd, 50);
        }
        cout << "(ZET)";
    }
}