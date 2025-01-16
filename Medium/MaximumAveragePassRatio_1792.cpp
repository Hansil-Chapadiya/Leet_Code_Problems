#include <iostream>
#include <vector>
#include <queue>
class MaximumAveragePassRatio_1792
{
private:
    /* data */
public:
    double maxAverageRatio(std::vector<std::vector<int>> &classes, int extraStudents)
    {
        int n = classes.size();
        // Lambda to calculate the improvement in pass ratio when adding one student
        auto calculategain = [](int passes_student, int class_size)
        {
            double passedratio = ((double)(passes_student + 1) / (class_size + 1) - (double)passes_student / class_size);
            return passedratio;
        };

        // Max-heap to store classes and their gain from adding an extra student
        std::priority_queue<std::pair<double, std::pair<int, int>>> max_pq;
        for (const auto &class_ : classes)
        {
            max_pq.push({calculategain(class_[0], class_[1]), {class_[0], class_[1]}});
        }

        // Distribute all extra students
        while (extraStudents-- > 0) // <-- fixed loop
        {
            auto [calculatedGain, class_information] = max_pq.top();
            max_pq.pop();
            int passed = class_information.first;
            int class_size = class_information.second;
            // Update the class with one more student passed
            max_pq.push({calculategain(passed + 1, class_size + 1), {passed + 1, class_size + 1}});
        }

        // Calculate the final average of the pass ratios for all classes
        double class_average_passed_ratio = 0;
        while (!max_pq.empty())
        {
            auto [calculatedGain, class_information] = max_pq.top();
            max_pq.pop();
            class_average_passed_ratio += ((double)class_information.first / class_information.second);
        }
        return class_average_passed_ratio / n;
    }
};
int main()
{
    std::vector<std::vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
    int extrastudents = 4;
    MaximumAveragePassRatio_1792 m1;
    m1.maxAverageRatio(classes, extrastudents);
    return 0;
}