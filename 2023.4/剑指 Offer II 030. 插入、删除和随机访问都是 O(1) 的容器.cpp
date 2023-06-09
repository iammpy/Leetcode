class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int,int> index;


public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index.find(val)!=index.end()) return false;
        nums.push_back(val);
        index[val]=nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index.find(val)==index.end()) return false;
        // int temp=index.count(val);
        nums[index[val]]=nums[nums.size()-1];
        index[nums[nums.size()-1]]=index[val];
        index.erase(val);
        nums.pop_back();
        return true;

    }
    
    /** Get a random element from the set. */
    int getRandom() {

        int randIdx = rand() % nums.size();
        return nums[randIdx];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
