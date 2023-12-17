//1. Brute (Without using additional maps for food to rating, cuisine) 
//2. Optimal

//BRUTE (TLE)
//Without using additional maps for food to rating, cuisine, iterating cuisine menu map

class FoodRatings {
    
    unordered_map<string, set<pair<int, string>>> cuisineMenu; //cannot use map, as we can have multiple foods with same rating
    unordered_map<int, string> ratingMap;
    
   
public:
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i = 0; i < cuisines.size(); i++)
        {
            string cuisine = cuisines[i];
            string food = foods[i];
            int rating = ratings[i];
            
            cuisineMenu[cuisine].insert({-rating, food});
            ratingMap[rating] = food;
            
        }
    }
    
    void changeRating(string food, int newRating) {
        
        for(auto i : cuisineMenu)
        {
            string cuisine = i.first;
            
            //set i.second
            for(auto j : i.second)
            {
                string mapFood = j.second;
                
                if(mapFood == food)
                {
                    int oldRating = -1 * (j.first);
                    
                    cuisineMenu[cuisine].erase({-oldRating, food});
                    ratingMap.erase(oldRating);
                    
                    cuisineMenu[cuisine].insert({-newRating, food});
                    ratingMap[newRating] = food;
                    
                    break;
                }
            }
            
        }
    }
    
    string highestRated(string cuisine) {
        
        return (*cuisineMenu[cuisine].begin()).second;
    }
    
    //map<string, 
};


//Optimal
//map food to rating and cuisine, so we can avoid iterating the map and the set

//SC: O(3*N + N + N) = O(N)

class FoodRatings { 
    
    unordered_map<string, set<pair<int, string>>> cuisineMenu; //cannot use map, as we can have multiple foods with same rating
    
    unordered_map<string, int> ratingMap; //a food can have only one rating
    unordered_map<string, string> cuisineMap; //a food can have only one cuisine
    
   
public:
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) { //TC: O(N + logN + logN + logN)
        
        for(int i = 0; i < cuisines.size(); i++)
        {
            string cuisine = cuisines[i];
            string food = foods[i];
            int rating = ratings[i];
            
            cuisineMenu[cuisine].insert({-rating, food});
            
            ratingMap[food] = rating;
            cuisineMap[food] = cuisine;
            
        }
    }
    
    void changeRating(string food, int newRating) { //TC: O(logN + logN + logN)
        
        int oldRating = ratingMap[food];
        string cuisine = cuisineMap[food];
        
        cuisineMenu[cuisine].erase({-oldRating, food});
        
        ratingMap[food] = newRating;
        
        cuisineMenu[cuisine].insert({-newRating, food});
        
    }
    
    string highestRated(string cuisine) {  //TC: O(1)
        
        return (*cuisineMenu[cuisine].begin()).second;
    }

};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
