#ifndef FSL_FILES_HXX
#define FSL_FILES_HXX

#include <fstream>

namespace fsl {

inline void ClearFile(const char* a_fileName) {
    std::ofstream file2clear(a_fileName);
    file2clear << "";
    file2clear.close();
}

} // fsl

#endif /* FSL_FILES_HXX */