
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Job {

    int profit, deadline;

    Job(int profit, int deadline) {
        this.profit = profit;
        this.deadline = deadline;
    }
};

class Solution {

    public ArrayList<Integer> jobSequencing(int[] deadline, int[] profit) {
        ArrayList<Job> jobs = new ArrayList<>();
        int n = deadline.length, maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = Math.max(maxDeadline, deadline[i]);
            jobs.add(new Job(profit[i], deadline[i]));
        }
        Collections.sort(jobs, (a, b) -> b.profit - a.profit);
        int hash[] = new int[maxDeadline];
        int maxJob = 0, maxProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = jobs.get(i).deadline - 1; j >= 0; j--) {
                if (hash[j] == 0) {
                    ++maxJob;
                    maxProfit += jobs.get(i).profit;
                    hash[j] = -1;
                    break;
                }
            }
        }
        return new ArrayList<>(Arrays.asList(maxJob, maxProfit));
    }
}

public class One {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.jobSequencing(new int[]{4, 1, 1, 1}, new int[]{20, 10, 40, 30}));//2 60

        System.out.println(sol.jobSequencing(new int[]{2, 1, 2, 1, 1}, new int[]{100, 19, 27, 25, 15}));//2 127
        System.out.println(sol.jobSequencing(new int[]{3, 1, 2, 2}, new int[]{50, 10, 20, 30})); // 3 100
    }
}
