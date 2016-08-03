#include <stdio.h>
#include <mxml.h>

void print_node(mxml_node_t *node);

int main(int argc, char *argv[])
{
    mxml_node_t *xml;
    mxml_node_t *data;
    mxml_node_t *node;
    mxml_node_t * group;
    mxml_node_t *child;

    xml = mxmlNewXML("1.0");
    data = mxmlNewElement(xml, "data");

    node = mxmlNewElement(data, "node");
    mxmlNewText(node, 0, "100");

    child = node->child;
    print_node(child);
    printf("%d\n", mxmlGetInteger(node));

    group = mxmlNewElement(data, "group");
    node = mxmlNewElement(group, "node");
    mxmlNewText(node, 0, "val4");

    mxmlDelete(xml);

    return 0;
}

void print_node(mxml_node_t *node)
{
    printf("node type:%d\n", node->type);

    switch(node->type)
    {
        case MXML_TEXT:
            printf("%s\n", mxmlGetText(node, NULL));
            break;
        case MXML_INTEGER:
            printf("%d\n", mxmlGetInteger(node));
            break;
        case MXML_REAL:
            printf("%f\n", mxmlGetReal(node));
            break;
        default:
            printf("node type is not text or int or real\n");
            break;
    }
}
