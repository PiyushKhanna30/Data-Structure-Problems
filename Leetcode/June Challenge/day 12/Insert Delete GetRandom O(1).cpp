class RandomizedSet {
private:
    unordered_map<int, int> indices;
    vector<int> vals;
public:
    RandomizedSet() {
    }
    bool insert(int val) {
        if (indices.find(val) == indices.end())   {
            indices[val]=vals.size();
            vals.push_back(val);
            
            return true;
        }
        return false;
    }
    bool remove(int val) {
        if (indices.find(val) == indices.end())   {
            return false;
        }
        int index = indices[val];
        vals[index] = vals[vals.size() - 1];
        indices[vals[index]] = index;
        vals.pop_back();
        indices.erase(val);

        return true;
    }
    int getRandom() {
        int pick = rand() % vals.size();
        return vals[pick];
    }
};