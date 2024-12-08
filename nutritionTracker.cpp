#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Food{
    string name;
    int calories;
    double protein;
    double carbs;
    double fats;
};

struct FoodLog {
    string foodName;
    double servings;
};

vector<Food> foodDatabase;
vector<FoodLog> foodLogs;

int goalCalories = 0;
double goalProtein = 0, goalCarbs = 0, goalFats = 0;

void addFood(){
    Food food;
    cout<<"Enter food name: \n";
    cin.ignore();
    getline(cin,food.name);
    cout<<"Enter calories per serving: \n";
    cin>>food.calories;
    cout<<"Enter protein (grams) per serving: \n";
    cin>>food.protein;
    cout<<"Enter carbohydrates (grams) per serving: \n";
    cin>>food.carbs;
    cout<<"Enter fats (grams) per serving: \n";
    cin>>food.fats;
    foodDatabase.push_back(food);
    cout<<"Food added successfully!\n";
}

void logFood(){
    cout<<"Available foods:\n";
    for(size_t i=0;i<foodDatabase.size();++i){
        cout<<i+1<<". "<<foodDatabase[i].name<<"\n";
    }
    int foodIndex;
    double servings;
    cout<<"Select the food number to log: \n";
    cin>>foodIndex;
    cout<<"Enter number of servings: \n";
    cin>>servings;
    FoodLog log={foodDatabase[foodIndex-1].name, servings};
    foodLogs.push_back(log);
    const Food& food=foodDatabase[foodIndex-1];
    cout<<"\nLogged "<<servings<<" serving(s) of "<<food.name<<".\n";
    cout<<fixed<<setprecision(2);
    cout<<"\nTotal calories: "<<food.calories*servings<<" cal\n";
    cout<<"Total protein: "<<food.protein*servings<<" g\n";
    cout<<"Total carbs: "<<food.carbs*servings<<" g\n";
    cout<<"Total fats: "<<food.fats*servings<<" g\n";
}


void setGoals(){
    cout<<"Enter your daily calorie goal: \n";
    cin>>goalCalories;
    cout<<"Enter your daily protein goal (grams): \n";
    cin>>goalProtein;
    cout<<"Enter your daily carbohydrate goal (grams): \n";
    cin>>goalCarbs;
    cout<<"Enter your daily fat goal (grams): \n";
    cin>>goalFats;
    cout<<"\nGoals set successfully!\n";
    cout<<"\nDaily Goals:\n";
    cout<<"Calories: "<<goalCalories<<" cal\n";
    cout<<"Protein: "<<goalProtein<<" g\n";
    cout<<"Carbs: "<<goalCarbs<<" g\n";
    cout<<"Fats: "<<goalFats<<" g\n";
}

void viewGoals() {
    int totalCalories=0;
    double totalProtein=0;
    double totalCarbs=0;
    double totalFats=0;
    for(size_t i=0;i<foodLogs.size();++i){
        FoodLog log=foodLogs[i];
        for(size_t j=0;j<foodDatabase.size();++j){
            Food food=foodDatabase[j];
            if(food.name==log.foodName){
                totalCalories+=food.calories*log.servings;
                totalProtein+=food.protein*log.servings;
                totalCarbs+=food.carbs*log.servings;
                totalFats+=food.fats*log.servings;
            }
        }
    }

    cout<<"\nComparison with goals:\n";
    cout<<"Calories:"<<totalCalories<<"/"<<goalCalories<<" cal ";
    if(totalCalories>goalCalories){
        cout<<"(Over by "<<totalCalories-goalCalories<<" cal)";
    }else if(totalCalories<goalCalories){
        cout<<"(Under by "<<goalCalories-totalCalories<<" cal)";
    }else{
        cout<<"(Met)";
    }
    cout<<"\n";

    cout<<"Protein:"<<totalProtein<<"/"<<goalProtein<<" g ";
    if(totalProtein>goalProtein){
        cout<<"(Over by "<<totalProtein-goalProtein<<" g)";
    }else if(totalProtein<goalProtein){
        cout<<"(Under by "<<goalProtein-totalProtein<<" g)";
    }else{
        cout<<"(Met)";
    }
    cout<<"\n";

    cout<<"Carbs: "<<totalCarbs <<"/"<<goalCarbs<<" g ";
    if(totalCarbs>goalCarbs){
        cout<<" (Over by "<<totalCarbs - goalCarbs << " g)";
    }else if(totalCarbs<goalCarbs) {
        cout<<" (Under by "<<goalCarbs-totalCarbs<<" g)";
    }else{
        cout<<" (Met)";
    }
    cout<<"\n";

    cout<<"Fats: "<<totalFats<<"/"<<goalFats<<" g ";
    if(totalFats>goalFats){
        cout<<" (Over by " << totalFats - goalFats << " g)";
    }else if(totalFats<goalFats){
        cout<<" (Under by "<<goalFats-totalFats<<" g)";
    }else{
        cout<<" (Met)";
    }
    cout<<"\n";
}

int main(){
    char choice;
    do{
        cout<<"\nNutrition Tracker (enter a letter):\n";
        cout<<"\n[A]dd food to database\n";
        cout<<"[L]og food\n";
        cout<<"[S]et nutrition goals\n";
        cout<<"[V]iew goals and intake\n";
        cout<<"[E]xit\n";
        cout<<"\nWhat would you like to do? \n";
        cin>>choice;
        switch(toupper(choice)){
            case 'A': addFood(); break;
            case 'L': logFood(); break;
            case 'S': setGoals(); break;
            case 'V': viewGoals(); break;
            case 'E': break;
        }
    } while(toupper(choice)!='E');
    return 0;
}
