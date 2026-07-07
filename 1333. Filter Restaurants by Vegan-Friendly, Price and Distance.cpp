#include "lib.h"

struct Node{
    int id;
    int rating;
    bool vegan;
    int price;
    int dist;
    Node(int _id, int _rating, bool _vegan, int _price, int _dist){
        id = _id;
        rating = _rating;
        vegan = _vegan;
        price = _price;
        dist = _dist;
    }
};
class Solution {
public:
    static bool cmp(const Node &a, const Node &b){
        if(a.rating != b.rating){
            return a.rating > b.rating;
        }else{
            return a.id > b.id;
        }
    }
    std::vector<int> filterRestaurants(std::vector<std::vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        std::vector<Node> arr;
        for(const auto &i : restaurants){
            if(veganFriendly && !i[2]) continue;
            if(i[3] > maxPrice) continue;
            if(i[4] > maxDistance) continue;
            Node newNode(i[0], i[1], i[2], i[3], i[4]);
            arr.push_back(newNode);
        }

        sort(arr.begin(), arr.end(), cmp);

        std::vector<int> id;
        for(auto &i : arr){
            id.push_back(i.id);
        }
        
        return id;
    }
};