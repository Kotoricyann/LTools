#include"TimeRecorder.h"

int main(){
    LTools::TimeRecorder recorder;
    recorder.record(1);
    
    for (int i = 0; i < 10; i++)
    {
        recorder.record(2);
        int j = 10000;
        while (j>0)
        {
            j--;
        }
        recorder.record(3);
        j = 60000;
        while (j>0)
        {
            j--;
        }
        recorder.record(4);
        j = 100000;
        while (j>0)
        {
            j--;
        }
        recorder.record(5);
    }
    
    recorder.display();
    
    system("pause");
    return 0;


}