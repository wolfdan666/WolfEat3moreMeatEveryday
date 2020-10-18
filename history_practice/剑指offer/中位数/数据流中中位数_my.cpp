class Solution {
   public:
    void Insert(double num) {
        if (((min.size() + max.size()) & 1) == 0) {
            if (max.size() > 0 && num < max[0]) {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<double>());

                num = max[0];

                pop_heap(max.begin(), max.end(), less<double>());
                max.pop_back();
            }

            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<double>());
        } else {
            if (min.size() > 0 && min[0] < num) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<double>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<double>());
                min.pop_back();
            }

            max.push_back(num);
            push_heap(max.begin(), max.end(), less<double>());
        }
    }

    double GetMedian() {
        int size = min.size() + max.size();
        // if (size == 0) throw exception("No numbers are available");

        double median = 0;
        if ((size & 1) == 1)
            median = min[0];
        else
            median = (min[0] + max[0]) / 2;

        return median;
    }

   private:
    vector<double> min;
    vector<double> max;
};