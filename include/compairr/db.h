/*
    Copyright (C) 2012-2021 Torbjorn Rognes and Frederic Mahe

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Contact: Torbjorn Rognes <torognes@ifi.uio.no>,
    Department of Informatics, University of Oslo,
    PO Box 1080 Blindern, NO-0316 Oslo, Norway
*/

/* structures and data types */

struct db;

// struct db
// {
//   seqinfo_t * seqindex;
//   uint64_t seqindex_alloc;
//   uint64_t sequences;
//   unsigned int longest;
//   unsigned int shortest;
//   char * residues_p;
//   uint64_t residues_alloc;
//   uint64_t residues_count;
//   uint64_t total_duplicate_count;
//   uint64_t repertoire_count;
//   uint64_t ignored_unknown;
//   uint64_t ignored_empty;
//   std::vector<std::string> repertoire_id_vector;
//   std::map<std::string, int> repertoire_id_map;
//   int col_junction;
//   int col_junction_aa;
//   int col_cdr3;
//   int col_cdr3_aa;
//   int col_duplicate_count;
//   int col_v_call;
//   int col_j_call;
//   int col_repertoire_id;
//   int col_sequence_id;
// };

/* functions in db.cc */

void db_init();

void db_exit();

struct db * db_create();

void parse_airr_tsv_header(char * line,
                           struct db * d,
                           bool require_sequence_id);

void parse_airr_tsv_line(char * line,
                         uint64_t lineno,
                         struct db * d,
                         bool require_sequence_id,
                         const char * default_repertoire_id);

void db_free(struct db * d);

void db_read(struct db * d,
             const char * filename,
             bool require_sequence_id,
             const char * default_repertoire_id);

void db_read(struct db *d,
             FILE *fp,
             bool require_sequence_id,
             const char *default_repertoire_id);

uint64_t db_getsequencecount(struct db * d);

uint64_t db_get_repertoire_count(struct db * d);

void db_set_repertoire_count(struct db * d, uint64_t count);

uint64_t db_getresiduescount(struct db * d);

unsigned int db_getlongestsequence(struct db * d);

char * db_getsequence(struct db * d, uint64_t seqno);

unsigned int db_getsequencelen(struct db * d, uint64_t seqno);

uint64_t db_gethash(struct db * d, uint64_t seqno);

uint64_t db_get_v_gene(struct db * d, uint64_t seqno);

uint64_t db_get_j_gene(struct db * d, uint64_t seqno);

uint64_t db_get_count(struct db * d, uint64_t seqno);

int db_get_repertoire_id_no(struct db * d, uint64_t seqno);

const char * db_get_repertoire_id(struct db * d, int repertoire_id_no);

char * db_get_sequence_id(struct db * d, uint64_t seqno);

void db_hash(struct db * d);

uint64_t db_get_v_gene_count();

uint64_t db_get_j_gene_count();

const char * db_get_v_gene_name(struct db * d, uint64_t seqno);

const char * db_get_j_gene_name(struct db * d, uint64_t seqno);

void db_fprint_sequence(FILE * f, struct db * d, uint64_t seqno);

char * db_get_keep_columns(struct db * d, uint64_t seqno);

void db_debug_print(const db* d, std::ostream& os);

unsigned int db_get_longest(struct db * d);

void db_set_longest(struct db * d, unsigned int longest);

unsigned int db_get_shortest(struct db * d);

void db_set_shortest(struct db * d, unsigned int shortest);

uint64_t db_get_ignored_unknown(struct db * d);

void db_set_ignored_unknown(struct db * d, uint64_t ignored_unknown);

uint64_t db_get_ignored_empty(struct db * d);

void db_set_ignored_empty(struct db * d, uint64_t ignored_empty);

std::vector<std::string> db_get_repertoire_id_vector(struct db * d);

void db_set_repertoire_id_vector(struct db * d, std::vector<std::string> vec);

uint64_t db_get_total_duplicate_count(struct db * d);

char * db_get_residues_p(struct db * d);

struct seqinfo_s * db_get_seqindex(struct db * d);

void db_set_seqinfo_s_seq(struct seqinfo_s * p, char * r);

unsigned int db_get_seqinfo_s_seqlen(struct seqinfo_s * p);

void db_set_seqinfo_s(struct db * d, char * r, uint64_t i);
