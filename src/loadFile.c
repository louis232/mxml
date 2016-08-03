#include "common.h"
#include <mxml.h>

int main(int argc ,char *argv[])
{
    if(argc != 2)
        err_quit("Usage:./loadFile filename");

    FILE *fp;
    mxml_node_t *tree;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
        err_sys("fopen file error");

    tree = mxmlLoadFile(NULL, fp, MXML_TEXT_CALLBACK);
    if(tree == NULL)
        err_quit("load xml file error");
    fclose(fp);

    fp = fopen("bak.xml", "w+");
    mxmlSaveFile(tree, fp, MXML_NO_CALLBACK);
    fclose(fp);
    return 0;
}
