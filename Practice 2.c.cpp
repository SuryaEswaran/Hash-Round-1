#include <stdio.h>

int findCandidateElement(int arr[], int len) {
    // This function returns the candidate element if it exists, otherwise -1
    int candidate = -1; // To hold the candidate element
    int count = 0; // Count of the current candidate

    // Finding a candidate for majority element
    for (int i = 0; i < len; i++) {
        if (count == 0) {
            candidate = arr[i]; // Set candidate to current element
            count = 1; // Start counting
        }
        else if (arr[i] == candidate) {
            count++; // Increment count if it matches
        }
        else {
            count--; // Decrement count if it does not match
        }
    }

    // Verify the candidate
    count = 0; // Reset count for verification
    for (int i = 0; i < len; i++) {
        if (arr[i] == candidate) {
            count++; // Count occurrences of the candidate
        }
    }

    // Check if it is indeed the majority
    if (count > len / 2) {
        return candidate; // Return the candidate element
    }
    else {
        return -1; // Return -1 if no majority element exists
    }
}

int main() {
    int arr[] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 }; // Example array
    int len = sizeof(arr) / sizeof(arr[0]); // Calculate array length

    int result = findCandidateElement(arr, len); // Find the candidate element

    // Output the result
    if (result != -1) {
        printf("Candidate element: %d\n", result);
    }
    else {
        printf("No candidate element found.\n");
    }

    return 0; // Indicate successful completion
}
