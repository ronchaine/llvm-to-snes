//===-- SNESTargetObjectFile.cpp - SNES Object Files ------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "SNESTargetObjectFile.h"

#include "llvm/BinaryFormat/ELF.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/GlobalValue.h"
#include "llvm/IR/Mangler.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCSectionELF.h"

#include "SNES.h"

namespace llvm {
void SNESTargetObjectFile::Initialize(MCContext &Ctx, const TargetMachine &TM) {
  Base::Initialize(Ctx, TM);
  // TODO: check the place where global variables would go
  // ProgmemDataSection =
  //     Ctx.getELFSection(".progmem.data", ELF::SHT_PROGBITS, ELF::SHF_ALLOC);
}

MCSection *
SNESTargetObjectFile::SelectSectionForGlobal(const GlobalObject *GO,
                                            SectionKind Kind,
                                            const TargetMachine &TM) const {
  // TODO: check the place where global variables would go
  // Global values in flash memory are placed in the progmem.data section
  // unless they already have a user assigned section.
  // if (SNES::isProgramMemoryAddress(GO) && !GO->hasSection())
  //   return ProgmemDataSection;

  // Otherwise, we work the same way as ELF.
  return Base::SelectSectionForGlobal(GO, Kind, TM);
}
} // end of namespace llvm

