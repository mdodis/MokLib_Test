#include "Test/Test.h"
#include "Test/Base.h"
#include "Importers/Importer.h"
#include "Importers/Import.h"

extern ImporterRegistry Importer_Registry;
#include "Images/TestImage.cpp"

int main(int argc, char *argv[]) {
    return TEST_UNIT(ImageSupport).run();
}

#include "Compile.inc"
#include "Importers/Importers.inc"
#include "Test/Compile.inc"