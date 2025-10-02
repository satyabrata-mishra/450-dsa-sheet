import java.util.Arrays;

class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        // Step 1: Create a list of jobs (start time, end time, profit)
        int n = startTime.length;
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }

        // Step 2: Sort jobs by end time (because we want to process in the order they
        // finish)
        Arrays.sort(jobs, (a, b) -> a.end - b.end);

        // Step 3: DP array to store the maximum profit at each job
        int[] dp = new int[n];
        dp[0] = jobs[0].profit; // The profit from the first job is just its own profit

        // Step 4: Fill DP array
        for (int i = 1; i < n; i++) {
            // Include current job and find the last non-overlapping job
            int includeProfit = jobs[i].profit;
            int lastNonConflictingJob = findLastNonConflictingJob(jobs, i);
            if (lastNonConflictingJob != -1) {
                includeProfit += dp[lastNonConflictingJob];
            }

            // Either include the current job or skip it
            dp[i] = Math.max(dp[i - 1], includeProfit);
        }

        // The maximum profit will be in the last element of the dp array
        return dp[n - 1];
    }

    // Helper function to find the last non-conflicting job (using a linear search)
    private int findLastNonConflictingJob(Job[] jobs, int index) {
        for (int i = index - 1; i >= 0; i--) {
            if (jobs[i].end <= jobs[index].start) {
                return i;
            }
        }
        return -1;
    }
}

// Job class to store each job's details
class Job {
    int start;
    int end;
    int profit;

    Job(int start, int end, int profit) {
        this.start = start;
        this.end = end;
        this.profit = profit;
    }
}

public class Twentysix {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(
                sol.jobScheduling(new int[] { 1, 2, 3, 3 }, new int[] { 3, 4, 5, 6 }, new int[] { 50, 10, 40, 70 }));// 120
        System.out.println(sol.jobScheduling(new int[] { 1, 2, 3, 4, 6 }, new int[] { 3, 5, 10, 6, 9 },
                new int[] { 20, 20, 100, 70, 60 }));// 150
        System.out.println(sol.jobScheduling(new int[] { 1, 1, 1 }, new int[] { 2, 3, 4 }, new int[] { 5, 6, 4 }));// 6
    }
}
