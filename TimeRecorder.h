#include<iostream>
#include<unordered_map>
#include<string>
#include<ctime>

#ifndef LTOOLSTIMERECORDER
#define LTOOLSTIMERECORDER

namespace LTools
{

    class TimeRecorder
    {
    private:
        std::unordered_map<int, std::unordered_map<int,unsigned int> > A;
        std::unordered_map<int, std::unordered_map<int,unsigned int> > V;
        std::clock_t lastTime;
        int lastID;
    public:
        TimeRecorder(/* args */);
        int record(int y){
            std::clock_t now = std::clock();
            int interval = now - lastTime;
            A[lastID][y] += interval;
            V[lastID][y] += 1;
            lastID = y;
            lastTime = now;
            return interval;
        };
        void display(){
            for (auto row = A.begin(); row != A.end(); row++)
            {
                int i = row->first;
                auto& line = row->second;
                for (auto it = line.begin(); it != line.end(); it++)
                {
                    int j = it->first;
                    std::cout<<i<<'-'<<j<<':'<<A[i][j]<<' '<<V[i][j]<<' '<<1.0*A[i][j]/V[i][j]<<std::endl;
                }
                
            }
            
        };
    };
    
    TimeRecorder::TimeRecorder(/* args */)
    {
        lastID = -1;
        lastTime = std::clock();
    }

    
} // namespace LTools

#endif