/* 
我的代码
在acwing上过4个样例，在csp上得70分，不想改了，去看答案吧。。。
 */
#include <iostream>
#include <vector>
using namespace std;
struct Text
{
    string sender;
    string reveiver;
    string type;
    int ip;
    int time;
};
struct Ip
{
    int ip;
    string user;
    int time;
    int state;
};
int N, Td, TM, Tm;
string H;
int n;
int main()
{
    cin >> N >> Td >> TM >> Tm;
    cin >> H;
    vector<Ip> ipPool(N + 1);
    for (int i = 1; i <= N; i++)
    {
        ipPool[i].ip = i;
        ipPool[i].user = "";
        ipPool[i].time = 0;
        ipPool[i].state = 0;
    }
    cin >> n;
    while (n--)
    {
        int curt;
        string sender, receiver, type;
        Ip res;
        int ip, endTime;
        cin >> curt >> sender >> receiver >> type >> ip >> endTime;
        for (int i = 1; i <= N; i++)
        {
            if (ipPool[i].time > 0 && ipPool[i].time <= curt)
            {
                if (ipPool[i].state == 1)
                {
                    ipPool[i].state = 0;
                    ipPool[i].user = "";
                    ipPool[i].time = 0;
                }
                else
                {
                    ipPool[i].state = 3;
                    ipPool[i].time = 0;
                }
            }
        }
        if (receiver != H && receiver != "*")
        {
            if (type != "REQ")
                continue;
        }
        if (receiver == "*" && type != "DIS")
            continue;
        if (receiver == "H" && type == "DIS")
            continue;
        if (type == "DIS")
        {
            int i = 1;
            for (; i <= N; i++)
            {
                if (ipPool[i].user == sender)
                    break;
            }
            if (i <= N)
            {
                ipPool[i].state = 1;
                ipPool[i].user = sender;
                if (endTime == 0)
                {
                    ipPool[i].time = curt + Td;
                }
                else
                {
                    int t = endTime - curt;
                    t = max(Tm, t);
                    t = min(TM, t);
                    ipPool[i].time = curt + t;
                }
                res = ipPool[i];
            }
            else
            {
                int i = 1;
                for (; i <= N; i++)
                {
                    if (ipPool[i].state == 0)
                        break;
                }
                if (i <= N)
                {
                    ipPool[i].state = 1;
                    ipPool[i].user = sender;
                    if (endTime == 0)
                    {
                        ipPool[i].time = curt + Td;
                    }
                    else
                    {
                        int t = endTime - curt;
                        t = max(Tm, t);
                        t = min(TM, t);
                        ipPool[i].time = curt + t;
                    }
                    res = ipPool[i];
                }
                else
                {
                    int i = 1;
                    for (; i <= N; i++)
                    {
                        if (ipPool[i].state == 3)
                            break;
                    }
                    if (i <= N)
                    {
                        ipPool[i].state = 1;
                        ipPool[i].user = sender;
                        if (endTime == 0)
                        {
                            ipPool[i].time = curt + Td;
                        }
                        else
                        {
                            int t = endTime - curt;
                            t = max(Tm, t);
                            t = min(TM, t);
                            ipPool[i].time = curt + t;
                        }
                        res = ipPool[i];
                    }
                    else
                        continue;
                }
            }
            cout << H << " " << sender << " "
                 << "OFR"
                 << " " << res.ip << " " << res.time << endl;
        }
        else if (type == "OFR")
        {
            continue;
        }
        else if (type == "REQ")
        {
            if (receiver != H)
            {
                for (int i = 1; i <= N; i++)
                {
                    if (ipPool[i].user == sender)
                    {
                        if (ipPool[i].state == 1)
                        {
                            ipPool[i].state = 0;
                            ipPool[i].user = "";
                            ipPool[i].time = 0;
                        }
                    }
                }
                continue;
            }
            if (ip < 1 || ip > N || (ipPool[ip].user != sender))
            {
                cout << H << " " << sender << " "
                     << "NAK"
                     << " " << ip << " " << 0 << endl;
                continue;
            }
            ipPool[ip].state = 2;
            if (endTime == 0)
            {
                ipPool[ip].time = curt + Td;
            }
            else
            {
                int t = endTime - curt;
                t = max(Tm, t);
                t = min(TM, t);
                ipPool[ip].time = curt + t;
            }
            cout << H << " " << sender << " "
                 << "ACK"
                 << " " << ip << " " << ipPool[ip].time << endl;
        }
        else if (type == "ACK")
        {
            continue;
        }
        else if (type == "NAK")
        {
            continue;
        }
    }

    return 0;
}