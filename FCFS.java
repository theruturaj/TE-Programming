import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of processes: ");
        int count_process = sc.nextInt();
        
        int process_arr[] = new int[count_process];
        
        for (int i=0; i<count_process; i++)
        {
            System.out.println("Enter Process: ");
            int get_process = sc.nextInt();
            process_arr[i]=get_process;
        }
        
        int mili_time[] = new int[count_process];
        
        for (int j=0; j<count_process; j++)
        {
            int mili = 0;
            if(j==0)
            {
                System.out.println("P0 execution time: 0");
                mili_time[0]=0;
            }
            else
            {
                mili_time[j] = mili_time[j-1]+process_arr[j-1];
                System.out.println("P"+j+" execution time:"+mili_time[j]);
            }
        }
    }
}
