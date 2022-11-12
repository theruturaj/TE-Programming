package spos;
import java.util.*;

class FCFS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of processes: ");
        int count_process = sc.nextInt();
        
        int process_arr[] = new int[count_process];
        
        for (int i=0; i<count_process; i++)
        {
            System.out.println("Enter Process-time: ");
            int get_process = sc.nextInt();
            process_arr[i]=get_process;
        }
        
        int mili_time[] = new int[count_process];
        
        System.out.println("Process\tBurst\tWaiting Time");
        for (int j=0; j<count_process; j++)
        {
            int mili = 0;
            if(j==0)
            {
                System.out.println("P0\t\t"+process_arr[0]+"\t\t0\n");
                mili_time[0]=0;
            }
            else
            {
                mili_time[j] = mili_time[j-1]+process_arr[j-1];
                System.out.println("P"+j+"\t\t"+process_arr[j]+"\t\t"+mili_time[j]+"\n");
            }
        }
        
        int wait_time_sum = 0;
        
        for (int k2:mili_time)
        {
            wait_time_sum = wait_time_sum+k2;
        }
        
        float avg_time = wait_time_sum/count_process;
        System.out.println("Average waiting time is: "+avg_time);
    }
}
