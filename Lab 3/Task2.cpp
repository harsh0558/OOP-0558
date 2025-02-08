#include <iostream>
using namespace std;

class FitnessTracker
{
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    float caloriesBurned;

public:
    FitnessTracker(string userName, int dailyStepGoal)
    {
        this->userName = userName;
        this->dailyStepGoal = dailyStepGoal;
        stepsTaken = 0;
        caloriesBurned = 0;
    }

    void logSteps(int steps)
    {
        stepsTaken += steps;
    }

    float calculateCaloriesBurned()
    {
        caloriesBurned = stepsTaken * 0.4; // assuming 0.4 calories are burned per step
        return caloriesBurned;
    }

    void displayProgress()
    {
        cout << "User: " << userName << endl;
        cout << "Daily Step Goal: " << dailyStepGoal << endl;
        cout << "Steps Taken: " << stepsTaken << endl;
        cout << "Calories Burned: " << caloriesBurned << endl;
    }

    void displayGoalMet()
    {
        if (stepsTaken >= dailyStepGoal)
        {
            cout << "Congratulations! You have met your daily step goal." << endl;
        }
        else
        {
            cout << "You have not met your daily step goal." << endl;
        }
    }
};

int main()
{

    FitnessTracker user1("laiba", 5000);
    user1.logSteps(2000);
    user1.calculateCaloriesBurned();
    user1.displayProgress();
    user1.displayGoalMet();

    return 0;
}