#include <chrono>
#include <iostream>
#include <array>
#include <vector>
using namespace std;
using namespace std::chrono;


/*
//
//Binary Search:
//	It's a Technique to search in an array for a selected item.
//How it works:
//	It divides the array into 2 sections and checks which section hasn't the selected item
//	(by comparing the item in the middle), and this section will be cancelled.
//	this operiton will be repeated till we find the selected item.

int binarySearch(int arr[], int low, int high, int selected)
{
	int length = sizeof(arr) / sizeof(arr[0]);
	int first = 0;
	int last = length - 1;
	int mid;
	bool found = false;
	while (first <= last && !found)
	{
		mid = (first + last) / 2;
		if (arr[mid] == selected)
			found = true;
		else if (arr[mid] > selected)
			last = mid - 1;
		else
			first = mid + 1;
	}
	if (found)
		return mid;
	else
		return -1;
}
*/

/*
Binary Insertion Sort:
	It's a Technique to sort an array with time complexity (n log(n)) in the worst case.
How it works:
	It begins from the second index and search (with binary search) for the nearest
	item to the selected one, if this item bigger than the selected item then the location
	will be before it, if not then the location will be after it.
*/
void BinaryInsertionSort(int a[], int n)
{
    int mid;
    int high, low, tmp;
    for (int i = 1; i < n; i++) {
        low = 0, high = i;
        mid = i / 2;
        cout << "n" << endl;
        do {
            if (a[i] > a[mid]) {
                low = mid + 1;
                cout << "n^2" << endl;
            }
            else if (a[i] < a[mid]) {
                high = mid;
                cout << "n^2" << endl;
            }
            else
                break;

            mid = low + ((high - low) / 2);
        } while (low < high);

        if (mid < i) {
            tmp = a[i];
            memmove(a + mid + 1, a + mid, sizeof(int) * (i - mid));
            a[mid] = tmp;
        }
    }
}

/*
Insertion Sort:
	It's a Technique to sort an array with time complexity (n^2) in the worst case.
How it works:
	It begins from the second index and compare it with the last one, if this index bigger
	then it is in the right location, if not then compare it to the elements before, this
	operation will be repeated till we find the right location.
*/
void insertionSort(int arr[], int n)
{
    for (int i = 1, j; i < n; i++){
        int tmp = arr[i];
        for (j = i; j > 0 && tmp < arr[j - 1]; j--)
            arr[j] = arr[j - 1];
        arr[j] = tmp;
    }
}

int main()
{
    //making two arrays for the best caseand worst case to test time complexity for each function
    int bestCase[10];
    for (int i = 0; i < 10; i++)
    {
        bestCase[i] = i;
    }
    int worstCase[10];
    for (int i = 9; i >= 0; i--)
    {
        worstCase[i] = 9 - i;
    }
    //store array size
    int n = sizeof(bestCase) / sizeof(bestCase[0]), i;


    //record time for the best Case in insertion function
    auto start = high_resolution_clock::now();
    insertionSort(bestCase, n);
    auto finish = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(finish - start);
    cout << "best Case insertion: "<< duration.count() << " microseconds" << endl;

    //record time for the worst Case in insertion function
    start = high_resolution_clock::now();
    insertionSort(worstCase, n);
    finish = high_resolution_clock::now();
    duration = duration_cast<microseconds>(finish - start);
    cout << "wort Case insertion: "<< duration.count() << " microseconds" << endl;
    //reverse the array after sodting it, so i can use it again in the second function
    for (int i = 9; i >= 0; i--)
    {
        worstCase[i] = 9 - i;
    }

    //record time for the best Case in Binary insertion function
    start = high_resolution_clock::now();
    BinaryInsertionSort(bestCase, n);
    finish = high_resolution_clock::now();
    duration = duration_cast<microseconds>(finish - start);
    cout << "best Case Binary insertion: "<< duration.count() << " microseconds" << endl;

    //record time for the worst Case in insertion function
    start = high_resolution_clock::now();
    BinaryInsertionSort(worstCase, n);
    finish = high_resolution_clock::now();
    duration = duration_cast<microseconds>(finish - start);
    cout << "worst Case Binary insertion: "<< duration.count() << " microseconds" << endl;
    return 0;
}