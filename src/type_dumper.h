// Copyright Hugh Perkins 2016

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "GlobalNames.h"

#include "llvm/IR/Type.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"

#include <string>
#include <map>
#include <set>

namespace cocl {

class TypeDumper {
public:
    TypeDumper(GlobalNames *globalNames) : globalNames(globalNames) {
    }
    std::string dumpType(llvm::Type *type);
    std::string dumpFunctionType(llvm::FunctionType *fn);
    std::string dumpPointerType(llvm::PointerType *ptr);
    std::string dumpIntegerType(llvm::IntegerType *type);
    std::string dumpStructType(llvm::StructType *type);
    std::string dumpAddressSpace(llvm::Type *type);
    std::string dumpArrayType(llvm::ArrayType *type);

    std::string dumpStructDefinitions();
    std::string dumpStructDefinition(llvm::StructType *type, std::string name);

    std::set<llvm::StructType *> structsToDefine;
    std::map<llvm::FunctionType *, std::string> functionsToDefine;

protected:
    // std::map<llvm::GlobalVariable *, std::string> globalVariablesToDefine;
    GlobalNames *globalNames = 0;
};

} // namespace cocl