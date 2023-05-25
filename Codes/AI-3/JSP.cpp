#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// A structure to represent a job
struct Job {
    char id;    // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is completed before or on the deadline
};

// Comparator function for sorting jobs
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

// Returns maximum profit from jobs
void printJobScheduling(vector<Job>& jobs) {
    int n = jobs.size();

    // Sort jobs according to decreasing order of profit
    sort(jobs.begin(), jobs.end(), comparison);

    vector<int> result(n);  // To store the sequence of jobs
    vector<bool> slot(n, false); // To keep track of free time slots

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (Note that we start
        // from the last possible slot)
        for (int j = min(n, jobs[i].dead) - 1; j >= 0; j--) {
            // Free slot found
            if (slot[j] == false) {
                result[j] = i;      // Add this job to the result
                slot[j] = true;     // Make this slot occupied
                break;
            }
        }
    }

    // Print the result
    cout << "Job Sequence: ";
    for (int i = 0; i < n; i++) {
        if (slot[i])
            cout << jobs[result[i]].id << " ";
    }
}

int main() {
    int numJobs;
    cout << "Enter the number of jobs: ";
    cin >> numJobs;

    vector<Job> jobs(numJobs);

    // Input job details from the user
    for (int i = 0; i < numJobs; i++) {
        cout << "Enter details for Job " << i + 1 << ":\n";
        cout << "  ID: ";
        cin >> jobs[i].id;
        cout << "  Deadline: ";
        cin >> jobs[i].dead;
        cout << "  Profit: ";
        cin >> jobs[i].profit;
    }

    // Call the function to print the maximum profit sequence of jobs
    cout << "Maximum profit sequence of jobs: ";
    printJobScheduling(jobs);

    return 0;
}







