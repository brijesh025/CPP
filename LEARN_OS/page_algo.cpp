// ***********FIFO**************** 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int page_count, frame_size;
    int total_faults = 0;

    cout << "Memory Page Replacement Simulator\n";
    cout << "Enter total number of pages to process: ";
    cin >> page_count;
    cout << "Enter memory frame size: ";
    cin >> frame_size;

    vector<int> page_requests(page_count);
    cout << "Enter the sequence of page requests:\n";
    for (int &page_req : page_requests)
    {
        cin >> page_req;
    }

    queue<int> memory_frames;
    unordered_set<int> loaded_pages;

    for (int requested_page : page_requests)
    {
        if (loaded_pages.find(requested_page) == loaded_pages.end())
        {
            if (memory_frames.size() == frame_size)
            {
                int removed_page = memory_frames.front();
                memory_frames.pop();
                loaded_pages.erase(removed_page);
                cout << "Memory full. Removing page " << removed_page << "\n";
            }

            memory_frames.push(requested_page);
            loaded_pages.insert(requested_page);
            total_faults++;
            cout << "Loading page " << requested_page << " into memory\n";
        }
        else
        {
            cout << "Page " << requested_page << " is already in memory\n";
        }
    }

    cout << "\nSimulation complete\n";
    cout << "Total page faults: " << total_faults << "\n";
    cout << "Page fault rate: " << fixed << setprecision(2)
         << (float)total_faults / page_count * 100 << "%\n";

    return 0;
}

// *********************Optimal Page Replacement Policy***************************
//
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int page_count, frame_size;
//     int total_faults = 0;

//     cout << "Optimal Page Replacement Simulator\n";
//     cout << "Enter total number of pages to process: ";
//     cin >> page_count;
//     cout << "Enter memory frame size: ";
//     cin >> frame_size;

//     vector<int> page_requests(page_count);
//     cout << "Enter the sequence of page requests:\n";
//     for (int &page_req : page_requests) {
//         cin >> page_req;
//     }

//     vector<int> memory_frames;
//     unordered_set<int> loaded_pages;

//     for (int i = 0; i < page_count; i++) {
//         int requested_page = page_requests[i];

//         if (loaded_pages.find(requested_page) == loaded_pages.end()) {
//             if (memory_frames.size() == frame_size) {
//                 // Find the page that will be used farthest in the future
//                 int farthest = -1;
//                 int page_to_remove = -1;

//                 for (int current_page : memory_frames) {
//                     int j;
//                     for (j = i + 1; j < page_count; j++) {
//                         if (page_requests[j] == current_page) {
//                             if (j > farthest) {
//                                 farthest = j;
//                                 page_to_remove = current_page;
//                             }
//                             break;
//                         }
//                     }
//                     if (j == page_count) {  // Page not used in future
//                         page_to_remove = current_page;
//                         break;
//                     }
//                 }

//                 auto it = find(memory_frames.begin(), memory_frames.end(), page_to_remove);
//                 memory_frames.erase(it);
//                 loaded_pages.erase(page_to_remove);
//                 cout << "Memory full. Removing page " << page_to_remove << "\n";
//             }

//             memory_frames.push_back(requested_page);
//             loaded_pages.insert(requested_page);
//             total_faults++;
//             cout << "Loading page " << requested_page << " into memory\n";
//         }
//         else {
//             cout << "Page " << requested_page << " is already in memory\n";
//         }
//     }

//     cout << "\nSimulation complete\n";
//     cout << "Total page faults: " << total_faults << "\n";
//     cout << "Page fault rate: " << fixed << setprecision(2)
//          << (float)total_faults / page_count * 100 << "%\n";

//     return 0;
// }
//

// ****************LRU (Least Recently Used) Page Replacement Policy**********************
//
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int page_count, frame_size;
//     int total_faults = 0;

//     cout << "LRU Page Replacement Simulator\n";
//     cout << "Enter total number of pages to process: ";
//     cin >> page_count;
//     cout << "Enter memory frame size: ";
//     cin >> frame_size;

//     vector<int> page_requests(page_count);
//     cout << "Enter the sequence of page requests:\n";
//     for (int &page_req : page_requests) {
//         cin >> page_req;
//     }

//     list<int> memory_frames;  // Using list for O(1) removal
//     unordered_map<int, list<int>::iterator> page_positions;  // Track positions for O(1) access

//     for (int requested_page : page_requests) {
//         if (page_positions.find(requested_page) == page_positions.end()) {
//             if (memory_frames.size() == frame_size) {
//                 int lru_page = memory_frames.back();
//                 memory_frames.pop_back();
//                 page_positions.erase(lru_page);
//                 cout << "Memory full. Removing LRU page " << lru_page << "\n";
//             }

//             memory_frames.push_front(requested_page);
//             page_positions[requested_page] = memory_frames.begin();
//             total_faults++;
//             cout << "Loading page " << requested_page << " into memory\n";
//         }
//         else {
//             // Move the accessed page to front (most recently used position)
//             memory_frames.erase(page_positions[requested_page]);
//             memory_frames.push_front(requested_page);
//             page_positions[requested_page] = memory_frames.begin();
//             cout << "Page " << requested_page << " is already in memory\n";
//         }
//     }

//     cout << "\nSimulation complete\n";
//     cout << "Total page faults: " << total_faults << "\n";
//     cout << "Page fault rate: " << fixed << setprecision(2)
//          << (float)total_faults / page_count * 100 << "%\n";

//     return 0;
// }
//

// *****************************MRU (Most Recently Used) Page Replacement Policy*************************
//
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int page_count, frame_size;
//     int total_faults = 0;

//     cout << "MRU Page Replacement Simulator\n";
//     cout << "Enter total number of pages to process: ";
//     cin >> page_count;
//     cout << "Enter memory frame size: ";
//     cin >> frame_size;

//     vector<int> page_requests(page_count);
//     cout << "Enter the sequence of page requests:\n";
//     for (int &page_req : page_requests) {
//         cin >> page_req;
//     }

//     list<int> memory_frames;  // Using list for O(1) removal
//     unordered_map<int, list<int>::iterator> page_positions;  // Track positions for O(1) access

//     for (int requested_page : page_requests) {
//         if (page_positions.find(requested_page) == page_positions.end()) {
//             if (memory_frames.size() == frame_size) {
//                 int mru_page = memory_frames.front();
//                 memory_frames.pop_front();
//                 page_positions.erase(mru_page);
//                 cout << "Memory full. Removing MRU page " << mru_page << "\n";
//             }

//             memory_frames.push_front(requested_page);
//             page_positions[requested_page] = memory_frames.begin();
//             total_faults++;
//             cout << "Loading page " << requested_page << " into memory\n";
//         }
//         else {
//             // Move the accessed page to front (most recently used position)
//             memory_frames.erase(page_positions[requested_page]);
//             memory_frames.push_front(requested_page);
//             page_positions[requested_page] = memory_frames.begin();
//             cout << "Page " << requested_page << " is already in memory\n";
//         }
//     }

//     cout << "\nSimulation complete\n";
//     cout << "Total page faults: " << total_faults << "\n";
//     cout << "Page fault rate: " << fixed << setprecision(2)
//          << (float)total_faults / page_count * 100 << "%\n";

//     return 0;
// }
//