//new thing, since unordered_Set doesn't allow a pair, you can use a string with comma :D

class Solution {
public:
    bool isPathCrossing(string path) {
        
        int x = 0;
        int y = 0;
        
        unordered_set<string> hashSet;
        
        hashSet.insert("0,0");
        
        for(int i = 0; i < path.length(); i++)
        {
            if(path[i] == 'N')
                x++;
            else if(path[i] == 'S')
                x--;
            else if(path[i] == 'E')
                y++;
            else
                y--;
            
            string point = to_string(x) + "," + to_string(y);
            
            if(hashSet.find(point) != hashSet.end())
                return true;
            
            hashSet.insert(point);
            
        }
        
        return false;
    }
};
