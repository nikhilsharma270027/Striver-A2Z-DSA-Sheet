#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> result;

        unordered_set<string> st(begin(supplies), end(supplies)); // Copy all elements from supplies into st.

        vector<bool> cooked(n, false);

        int count = n;

        while (count--) { // O(n)
            for (int j = 0; j < n; j++) { // O(n)
                if (cooked[j]) { // If already cooked, continue
                    continue;
                }

                bool canCook = true;
                for (int k = 0; k < ingredients[j].size(); k++) { // O(m)
                    // If ingredient is missing, we cannot cook
                    if (!st.count(ingredients[j][k])) {
                        canCook = false;
                    }
                }

                if (canCook) {
                    st.insert(recipes[j]);
                    result.push_back(recipes[j]);
                    cooked[j] = true;
                }
            }
        }
        return result;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    vector<string> recipes = {"bread"};
    vector<vector<string>> ingredients = {{"yeast", "flour"}};
    vector<string> supplies = {"yeast", "flour", "corn"};

    vector<string> result = sol.findAllRecipes(recipes, ingredients, supplies);

    // Print the result
    cout << "Recipes that can be made: ";
    for (const string& recipe : result) {
        cout << recipe << " ";
    }
    cout << endl;

    return 0;
}
