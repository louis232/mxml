#include "common.h"
#include <mxml.h>

int main(int argc, char *argv[])
{
    //const char *xml = "<?xml version=\"1.0\" encoding=\"utf-8\" ?><data>hello</data>";
    const char *xml = "<data>hello</data>";
    mxml_node_t *tree;

    tree = mxmlLoadString(NULL, xml, MXML_TEXT_CALLBACK);
    if(tree == NULL)
        err_quit("load from string error");

    FILE *fp = fopen("saveFromString.xml", "w+");
    mxmlSaveFile(tree, fp, MXML_NO_CALLBACK);
    fclose(fp);

    char *buffer = mxmlSaveAllocString(tree, MXML_NO_CALLBACK);
    puts(buffer);
    free(buffer);

    return 0;
}
