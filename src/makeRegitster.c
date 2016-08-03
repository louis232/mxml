#include "common.h"
#include <stdio.h>
#include <mxml.h>
#include <time.h>

int main(int argc, char *argv[])
{
    mxml_node_t *xml;
    mxml_node_t *msg;
    mxml_node_t *node;
    
    xml = mxmlNewElement(NULL, "xml");
    
    node = mxmlNewElement(xml, "From");
    mxmlNewText(node, 0, "aaa");

    node = mxmlNewElement(xml, "To");
    mxmlNewText(node, 0, "bbb");

    msg = mxmlNewElement(xml, "MsgType");
    mxmlNewText(msg, 0, "REGISTER");

    node = mxmlNewElement(msg, "UserName");
    mxmlNewText(node, 0, "luqiang");
    node = mxmlNewElement(msg, "Time");
    time_t time_now = time(NULL);
    mxmlNewText(node, 0, ctime(&time_now));

    char buffer[1024] = {0};
    mxmlSaveString(xml, buffer, 1024, MXML_NO_CALLBACK);
    printf("%s\n", buffer);

    mxmlDelete(xml);

    return 0;
}
