#include <compairr/compairr.h>
#include <iostream>

int main(int argc, char** argv)
{
  logfile = stderr;

  arch_srandom(1);

  args_init(argc, argv);

  open_files();

  if (opt_version || opt_help)
    {
      show_header();
      if (opt_help)
        args_usage();
      close_files();
      exit(0);
    }

  show_header();

  show_time("Start time:        ");

  args_show();

  fprintf(logfile, "\n");

  if (opt_matrix || opt_existence)
    overlap(input1_filename, input2_filename);
  else if (opt_deduplicate)
    dedup(input1_filename);
  else
    cluster(input1_filename);

  show_time("End time:          ");

  if (keep_columns_no)
    {
      xfree(keep_columns_no);
      keep_columns_no = nullptr;
    }

  if (keep_columns_names)
    {
      xfree(keep_columns_names);
      keep_columns_names = nullptr;
    }

  if (keep_columns_strings)
    {
      xfree(keep_columns_strings);
      keep_columns_strings = nullptr;
    }

  close_files();
}