#include<iostream>
using namespace std;
class arrays
{
public:
    int array_l[10];
    int counter, max, S, E, sd, ed;
    arrays()
    {
        counter = 0;
        S = 0;
        E = 0;
        max = -1;
        cout << " Enter your elements of array \n";
        for (int i = 0; i < 10; i++)
        {
            cin >> array_l[i];
        }
    }
    void consective_ones()
    {
        int scount = 0;
        for (int i = 0; i < 10; i++)
        {
            if (array_l[i] == 1 && scount == 0)
            {
                sd = i;
                counter++;
                scount = 1;
            }
            else if (array_l[i] == 1)
            {
                counter++;
            }
            else if (array_l[i] != 1 && scount == 1)
            {
                ed = i - 1;
                if (counter > max)
                {
                    max = counter;
                    S = sd;
                    E = ed;
                }
                counter = 0;
                scount = 0;

            }
        }

    }
    void result()
    {
        cout << "Start Index Of Array : " << S << endl;
        cout << "End  Index Of Array : " << E << endl;
        cout << "Max Consecutive 1's in the Array are : " << max << endl;
    }
};
int main()
{
    arrays a1;
    a1.consective_ones();
    a1.result();
    return 0;
}