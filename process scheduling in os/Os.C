#include <stdio.h>

#define MAX 100

void FCFS(int n);
void SJF(int n);
void LJF(int n);
void SRTF(int n);
void LRTF(int n);
void RR(int n);
void Priority(int n);
void MLQ(int n);
void MLFQ(int n);

int main() {
    int choice, n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nCPU Scheduling Algorithms:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Longest Job First (LJF)\n");
    printf("4. Shortest Remaining Time First (SRTF)\n");
    printf("5. Longest Remaining Time First (LRTF)\n");
    printf("6. Round Robin (RR)\n");
    printf("7. Priority Scheduling (Non-preemptive)\n");
    printf("8. Multilevel Queue Scheduling\n");
    printf("9. Multilevel Feedback Queue Scheduling\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: FCFS(n); break;
        case 2: SJF(n); break;
        case 3: LJF(n); break;
        case 4: SRTF(n); break;
        case 5: LRTF(n); break;
        case 6: RR(n); break;
        case 7: Priority(n); break;
        case 8: MLQ(n); break;
        case 9: MLFQ(n); break;
        default: printf("Invalid choice!\n");
    }

    return 0;
}

// ------------------------- 1. FCFS -------------------------
void FCFS(int n) {
    int at[MAX], bt[MAX], ct[MAX], tat[MAX], wt[MAX];
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for(int i=0;i<n;i++)
        scanf("%d %d",&at[i], &bt[i]);

    int time=0;
    for(int i=0;i<n;i++){
        if(time < at[i]) time=at[i];
        time+=bt[i];
        ct[i]=time;
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
}

// ------------------------- 2. SJF (Non-preemptive) -------------------------
void SJF(int n){
    int at[MAX], bt[MAX], ct[MAX], tat[MAX], wt[MAX], completed[MAX];
    for(int i=0;i<n;i++) completed[i]=0;
    printf("Enter Arrival Time and Burst Time:\n");
    for(int i=0;i<n;i++) scanf("%d %d",&at[i],&bt[i]);

    int time=0, count=0;
    while(count<n){
        int idx=-1, min_bt=100000;
        for(int i=0;i<n;i++){
            if(at[i]<=time && !completed[i] && bt[i]<min_bt){
                min_bt=bt[i]; idx=i;
            }
        }
        if(idx==-1){time++; continue;}
        time+=bt[idx];
        ct[idx]=time;
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];
        completed[idx]=1;
        count++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
}

// ------------------------- 3. LJF (Non-preemptive) -------------------------
void LJF(int n){
    int at[MAX], bt[MAX], ct[MAX], tat[MAX], wt[MAX], completed[MAX];
    for(int i=0;i<n;i++) completed[i]=0;
    printf("Enter Arrival Time and Burst Time:\n");
    for(int i=0;i<n;i++) scanf("%d %d",&at[i],&bt[i]);

    int time=0, count=0;
    while(count<n){
        int idx=-1, max_bt=-1;
        for(int i=0;i<n;i++){
            if(at[i]<=time && !completed[i] && bt[i]>max_bt){
                max_bt=bt[i]; idx=i;
            }
        }
        if(idx==-1){time++; continue;}
        time+=bt[idx];
        ct[idx]=time;
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];
        completed[idx]=1;
        count++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
}

// ------------------------- 4. SRTF (Preemptive) -------------------------
void SRTF(int n){
    int at[MAX], bt[MAX], rt[MAX], ct[MAX], tat[MAX], wt[MAX];
    printf("Enter Arrival and Burst Time:\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    int completed=0, time=0;
    while(completed<n){
        int idx=-1, min_rt=100000;
        for(int i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && rt[i]<min_rt){
                min_rt=rt[i]; idx=i;
            }
        }
        if(idx==-1){time++; continue;}
        rt[idx]--;
        time++;
        if(rt[idx]==0){
            completed++;
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
}

// ------------------------- 5. LRTF (Preemptive) -------------------------
void LRTF(int n){
    int at[MAX], bt[MAX], rt[MAX], ct[MAX], tat[MAX], wt[MAX];
    printf("Enter Arrival and Burst Time:\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    int completed=0, time=0;
    while(completed<n){
        int idx=-1, max_rt=-1;
        for(int i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && rt[i]>max_rt){
                max_rt=rt[i]; idx=i;
            }
        }
        if(idx==-1){ time++; continue; }

        rt[idx]--;
        time++;

        if(rt[idx]==0){
            completed++;
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];   // <-- use idx, not i
            wt[idx]=tat[idx]-bt[idx];   // <-- use idx, not i
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
}


// ------------------------- 6. Round Robin (Preemptive) -------------------------
void RR(int n){
    int at[MAX], bt[MAX], rt[MAX], ct[MAX], tat[MAX], wt[MAX];
    printf("Enter Arrival and Burst Time:\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    int tq;
    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int completed=0, time=0;
    while(completed<n){
        int done=1;
        for(int i=0;i<n;i++){
            if(rt[i]>0 && at[i]<=time){
                done=0;
                if(rt[i]<=tq){
                    time+=rt[i];
                    rt[i]=0;
                    ct[i]=time;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];
                    completed++;
                } else {
                    time+=tq;
                    rt[i]-=tq;
                }
            }
        }
        if(done) time++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
}

// ------------------------- 7. Priority (Non-preemptive) -------------------------
void Priority(int n){
    int at[MAX], bt[MAX], pr[MAX], ct[MAX], tat[MAX], wt[MAX], completed[MAX];
    for(int i=0;i<n;i++) completed[i]=0;
    printf("Enter Arrival Time, Burst Time, Priority:\n");
    for(int i=0;i<n;i++) scanf("%d %d %d",&at[i],&bt[i],&pr[i]);

    int time=0, count=0;
    while(count<n){
        int idx=-1;
        for(int i=0;i<n;i++){
            if(at[i]<=time && !completed[i]){
                if(idx==-1 || pr[i]<pr[idx]) idx=i;
            }
        }
        if(idx==-1){time++; continue;}
        time+=bt[idx];
        ct[idx]=time;
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];
        completed[idx]=1;
        count++;
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
}

// ------------------------- 8. Multilevel Queue -------------------------
void MLQ(int n){
    int bt[MAX], q[MAX], ct[MAX], tat[MAX], wt[MAX];
    printf("Enter Burst Time and Queue Number (1/2):\n");
    for(int i=0;i<n;i++) scanf("%d %d",&bt[i],&q[i]);

    int time=0;
    for(int queue=1; queue<=2; queue++){
        for(int i=0;i<n;i++){
            if(q[i]==queue){
                time+=bt[i];
                ct[i]=time;
                tat[i]=ct[i]; // AT=0
                wt[i]=tat[i]-bt[i];
            }
        }
    }

    printf("\nP\tQueue\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1,q[i],bt[i],ct[i],tat[i],wt[i]);
}

// ------------------------- 9. Multilevel Feedback Queue -------------------------
void MLFQ(int n){
    int bt[MAX], rt[MAX], ct[MAX];
    printf("Enter Burst Time for each process:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }

    int tq1=2, tq2=4, time=0, completed=0;

    // Queue1 RR
    while(completed<n){
        int done=1;
        for(int i=0;i<n;i++){
            if(rt[i]>0){
                done=0;
                if(rt[i]<=tq1){
                    time+=rt[i];
                    rt[i]=0;
                    ct[i]=time; completed++;
                } else {
                    time+=tq1;
                    rt[i]-=tq1;
                }
            }
        }
        if(done) break;
    }

    // Queue2 FCFS
    for(int i=0;i<n;i++){
        if(rt[i]>0){
            time+=rt[i];
            rt[i]=0;
            ct[i]=time;
        }
    }

    printf("\nP\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        int tat=ct[i]; // AT=0
        int wt=tat-bt[i];
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], ct[i], tat, wt);
    }
}
