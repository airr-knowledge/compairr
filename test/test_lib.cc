#include "../include/compairr/api.h"
#include <iostream>

int main(void)
{
    std::vector<std::string> argv_strs;
    argv_strs.push_back("filler for prog_name, doesn't matter but needs to be here");
    argv_strs.push_back("-m");
    argv_strs.push_back("seta.tsv");
    argv_strs.push_back("setb.tsv");
    argv_strs.push_back("-d");
    argv_strs.push_back("1");
    argv_strs.push_back("-i");
    argv_strs.push_back("-l");
    argv_strs.push_back("compairr.log");
    argv_strs.push_back("-o");
    argv_strs.push_back("output.tsv");

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

    db_init();
    db * d1 = db_create();
    db_read(d1, "seta.tsv", false, "1");

    db * d2 = db_create();
    db_read(d2, "setb.tsv", false, "2");

    // std::cout << db_getlongestsequence(d1) << std::endl;
    // compairr::computeOverlap("seta.tsv", "setb.tsv");
    compairr::computeOverlap(d1, d2, false);
    // db_debug_print(d1, std::cout);
    // std::cout << "------------------------" << std::endl;
    // db_debug_print(d2, std::cout);
    close_files();

    // compairr::runOverlap("seta.tsv", "setb.tsv", 1, TRUE, "output.tsv", "compairr.log");
    // compairr::runOverlap("seta.tsv", "setb.tsv");
}