// Copyright (c) 2022 Cory Fields
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "desig_init.h"

#include <clang-tidy/ClangTidyModule.h>
#include <clang-tidy/ClangTidyModuleRegistry.h>

class BitcoinModule final : public clang::tidy::ClangTidyModule {
public:
  void addCheckFactories(clang::tidy::ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<bitcoin::DesigInitCheck>("bitcoin-init-list");
  }
};

static clang::tidy::ClangTidyModuleRegistry::Add<BitcoinModule>
    X("bitcoin-module", "Adds bitcoin checks.");

volatile int PropagateEarlyExitCheckAnchorSource = 0;
