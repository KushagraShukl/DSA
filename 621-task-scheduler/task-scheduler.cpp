class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count the frequency of every task
        unordered_map<char, int> freq;

        for (char task : tasks) {
            freq[task]++;
        }


        // Step 2: Create a max heap
        // The task with the highest frequency will be on top.
        priority_queue<int> pq;

        for (auto it : freq) {
            pq.push(it.second);
        }


        // Step 3: Cooldown queue
        //
        // We store:
        // {remaining frequency, time when task becomes available}
        //
        // Example:
        // {2, 5} means:
        //   - 2 occurrences of this task are still remaining
        //   - task can be used again at time 5
        queue<pair<int, int>> cooldown;


        // Current time / number of intervals
        int time = 0;


        // Continue until:
        // 1. No task is left in the heap
        // 2. No task is waiting in cooldown
        while (!pq.empty() || !cooldown.empty()) {

            // Move to the next time interval
            time++;


            // If there is a task available to execute
            if (!pq.empty()) {

                // Get the task with the highest remaining frequency
                int count = pq.top();
                pq.pop();


                // Execute this task once
                count--;


                // If this task still has remaining occurrences,
                // put it into cooldown.
                if (count > 0) {

                    // It can be used again after 'n' intervals.
                    cooldown.push({count, time + n});
                }
            }


            // Check whether the task at the front of the
            // cooldown queue has completed its cooldown.
            //
            // If available, move it back into the max heap.
            if (!cooldown.empty() &&
                cooldown.front().second == time) {

                // Get the task's remaining frequency
                int count = cooldown.front().first;

                cooldown.pop();

                // Task is available again
                pq.push(count);
            }
        }


        // Total time includes both:
        // - actual task executions
        // - idle intervals
        return time;
    }
};