#pragma once
#include <compairr/compairr.h>

// struct db {
//     seqinfo_t * seqindex; //
//     uint64_t seqindex_alloc;
//     uint64_t sequences;
//     unsigned int longest;
//     unsigned int shortest;
//     char * residues_p; //
//     uint64_t residues_alloc;
//     uint64_t residues_count;
//     uint64_t total_duplicate_count;
//     uint64_t repertoire_count;
//     std::vector<std::string> repertoire_id_vector;
//     std::unordered_map<std::string, uint64_t> repertoire_id_map;
//     unsigned int col_junction;
//     unsigned int col_junction_aa;
//     unsigned int col_cdr3;
//     unsigned int col_cdr3_aa;
//     unsigned int col_duplicate_count;
//     unsigned int col_v_call;
//     unsigned int col_j_call;
//     unsigned int col_repertoire_id;
//     unsigned int col_sequence_id;
// };

namespace compairr
{

    void computeOverlap(const char * set1_filename, const char * set2_filename);

    void computeOverlap(db * d1, db * d2, bool d2eqd1=false);

    void runOverlap(const char * set1_filename, const char * set2_filename, const int difference=0, const bool indels=true, const char * output = nullptr, const char * log = nullptr);
    
    void runOverlap(db * set1, db * set2, const int difference=0, const bool indels=true, const char * output = nullptr, const char * log = nullptr);
}

