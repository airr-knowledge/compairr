#pragma once
#include <compairr/compairr.h>

namespace compairr
{

    void computeOverlap(const char * set1_filename, const char * set2_filename);

    void computeOverlap(db * d1, db * d2, bool d2eqd1=false);

    void runOverlap(const char * set1_filename, const char * set2_filename, const int difference=0, const bool indels=TRUE, const char * output = nullptr, const char * log = nullptr);
    
    void runOverlap(db * set1, db * set2, const int difference=0, const bool indels=TRUE, const char * output = nullptr, const char * log = nullptr);
}

