#include <iostream>
#include <algorithm> // برای استفاده از تابع sort

void getInput(int arr[], int& n) {
    std::cout << "تعداد عناصر آرایه را وارد کنید: ";
    std::cin >> n;
    std::cout << "عناصر آرایه را وارد کنید:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}

void printArray(int arr[], int n) {
    std::cout << "عناصر آرایه: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int calculateSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(int arr[], int n) {
    return static_cast<double>(calculateSum(arr, n)) / n;
}

void sortArray(int arr[], int n, int sortedArr[]) {
    std::copy(arr, arr + n, sortedArr);
    std::sort(sortedArr, sortedArr + n);
}

int searchValue(int arr[], int n, int value) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[100]; // تعریف آرایه با حداکثر اندازه ۱۰۰
    int n; // تعریف متغیر تعداد عناصر آرایه

    getInput(arr, n); // گرفتن ورودی از کاربر
    printArray(arr, n); // چاپ آرایه

    int maxNum = findMax(arr, n); // یافتن بزرگترین عنصر
    std::cout << "بزرگترین عنصر: " << maxNum << std::endl;

    int minNum = findMin(arr, n); // یافتن کوچکترین عنصر
    std::cout << "کوچکترین عنصر: " << minNum << std::endl;

    int sum = calculateSum(arr, n); // محاسبه مجموع عناصر
    std::cout << "مجموع عناصر: " << sum << std::endl;

    double avg = calculateAverage(arr, n); // محاسبه میانگین عناصر
    std::cout << "میانگین عناصر: " << avg << std::endl;

    int sortedArr[100]; // تعریف آرایه برای ذخیره آرایه مرتب شده
    sortArray(arr, n, sortedArr); // مرتب‌سازی آرایه
    std::cout << "آرایه مرتب شده: ";
    printArray(sortedArr, n); // چاپ آرایه مرتب شده

    int searchVal;
    std::cout << "یک مقدار برای جستجو در آرایه وارد کنید: ";
    std::cin >> searchVal;
    int index = searchValue(arr, n, searchVal); // جستجو در آرایه
    if (index != -1) {
        std::cout << "مقدار " << searchVal << " در اندیس: " << index << " یافت شد." << std::endl;
    }
    else {
        std::cout << "مقدار در آرایه یافت نشد." << std::endl;
    }

    return 0;
}
