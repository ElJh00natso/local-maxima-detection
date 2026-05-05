#include "StripsData.h"
#include <vector>
class ERatioAthAlgTool{
    public:

    void searchMaxLocal(const StripsData& data, std::vector<Calocell>& maxlocal);

    void realCandidates(std::vector<Calocell> maxlocal);

    

};