if ! [ -e ../src/libcompairr.a ] ; then
    echo The libcompairr.a binary is missing
    echo Test failed.
    exit 1
fi

./test_lib

if diff -q output.tsv expected.tsv; then
    echo Test completed successfully.
    # rm output.tsv
else
    echo Test failed.
    exit 1
fi