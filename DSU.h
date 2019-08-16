#ifndef DSU_H
#define DSU_H
#include <vector>

class DSU
{
    public:
        DSU(int n)
        {
            countOfGroups = n;
            parents = std::vector<int>(n);
            ranks = std::vector<int>(n,1);
            for(int i = 0; i < n; i++)
                  parents[i] = i;
        }
        void MakeSet();
        void Union(int id1, int id2);
        int Find(int id);
        int getCountOfGroups()
        {
            return countOfGroups;
        }
    private:
        int countOfGroups;
        std::vector<int> parents;
        std::vector<int> ranks;
};
void DSU::MakeSet()
{
   countOfGroups++;
   int id = parents.size();
   parents.push_back(id);
   ranks.push_back(1);
}

void DSU::Union(int id1, int id2)
{
    int group1 = Find(id1);
    int group2 = Find(id2);
    if(group1 == group2)
          return;
    countOfGroups--;
    if(ranks[group1] >= ranks[group2])
    {
        parents[group2] = group1;
        ranks[group1] += ranks[group2];
    }
    else
    {
        parents[group1] = group2;
        ranks[group2] += ranks[group1];
    }
}

int DSU::Find(int id)
{
   int parent = parents[id];
   if(parent == id)
      return parent;
   else return parents[id] = Find(parent);
}

#endif // DSU_H
