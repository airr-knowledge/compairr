#include <compairr/compairr.h>

struct db;

namespace compairr {
    // void build_db(const char * set1_filename) {

    // }

    void computeOverlap(const char * set1_filename, const char * set2_filename)
    {
        overlap(set1_filename, set2_filename);
    }
    
    void computeOverlap(db * d1, db * d2, bool d2eqd1)
    {
        overlap(d1, d2, d2eqd1);
    }

    void runOverlap(const char * set1_filename, const char * set2_filename, const int difference, const bool indels, const char * output, const char * log) {
        std::vector<std::string> argv_strs;
        
        std::string set1_filename_str(set1_filename);
        std::string set2_filename_str(set2_filename);
        std::string difference_str = std::to_string(difference);
        std::string log_str;
        if(log) {log_str = log;}
        std::string output_str;
        if(output) {output_str = output;}

        argv_strs.push_back("filler for prog_name, doesn't matter but needs to be here");
        argv_strs.push_back("-m");
        argv_strs.push_back(set1_filename_str);
        argv_strs.push_back(set2_filename_str);
        if(difference>0) {
            argv_strs.push_back("-d");
            argv_strs.push_back(difference_str);
        };
        if(indels && difference==1) {argv_strs.push_back("-i");}
        if(log) {
            argv_strs.push_back("-l");
            argv_strs.push_back(log_str);
        }
        if(output) {
            argv_strs.push_back("-o");
            argv_strs.push_back(output_str);
        }

        // vector of char* pointing to the mutable strings
        std::vector<char*> argv_vec;
        for (auto &s : argv_strs) {
            argv_vec.push_back(&s[0]);
        }

        int argc = argv_vec.size();
        char **argv = argv_vec.data();

        logfile = stderr;

        arch_srandom(1);

        args_init(argc, argv);

        open_files();

        fprintf(logfile, "\n");

        overlap(set1_filename, set2_filename);

        close_files();
    }

    void runOverlap(db * set1, db * set2, const int difference, const bool indels, const char * output, const char * log) {
        std::vector<std::string> argv_strs;
        
        // std::string set1_filename_str(set1_filename);
        // std::string set2_filename_str(set2_filename);
        std::string difference_str = std::to_string(difference);
        std::string log_str;
        if(log) {log_str = log;}
        std::string output_str;
        if(output) {output_str = output;}

        argv_strs.push_back("filler for prog_name, doesn't matter but needs to be here");
        argv_strs.push_back("-m");
        argv_strs.push_back("set1"); // filler
        argv_strs.push_back("set2"); // filler
        if(difference>0) {
            argv_strs.push_back("-d");
            argv_strs.push_back(difference_str);
        };
        if(indels && difference==1) {argv_strs.push_back("-i");}
        if(log) {
            argv_strs.push_back("-l");
            argv_strs.push_back(log_str);
        }
        if(output) {
            argv_strs.push_back("-o");
            argv_strs.push_back(output_str);
        }

        // vector of char* pointing to the mutable strings
        std::vector<char*> argv_vec;
        for (auto &s : argv_strs) {
            argv_vec.push_back(&s[0]);
        }

        int argc = argv_vec.size();
        char **argv = argv_vec.data();

        logfile = stderr;

        arch_srandom(1);

        args_init(argc, argv);

        open_files();

        fprintf(logfile, "\n");

        overlap(set1, set2, false);

        close_files();
    }
}