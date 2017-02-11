/*
Copyright 2016 Soramitsu Co., Ltd.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#ifndef CORE_MODEL_TRANSACTION_BUILDER_ADD_DOMAIN_HPP
#define CORE_MODEL_TRANSACTION_BUILDER_ADD_DOMAIN_HPP

#include "../transaction_builder_base.hpp"
#include "../../transaction.hpp"
#include "../../type_signatures/add.hpp"
#include "../../objects/domain.hpp"
#include <iostream>

namespace transaction {

template <>
class TransactionBuilder<type_signatures::Add<object::Domain>> {
 public:
  TransactionBuilder() = default;
  TransactionBuilder(const TransactionBuilder&) = default;
  TransactionBuilder(TransactionBuilder&&) = default;

  TransactionBuilder& setSender(std::string sender) {
    if (_isSetSender) {
      throw std::domain_error(std::string("Duplicate sender in ") +
                              "add/add_domain_builder_template.hpp");
    }
    _isSetSender = true;
    _sender = std::move(sender);
    return *this;
  }

  TransactionBuilder& setDomain(object::Domain object) {
    if (_isSetDomain) {
      throw std::domain_error(std::string("Duplicate ") + "Domain" + " in " +
                              "add/add_domain_builder_template.hpp");
    }
    _isSetDomain = true;
    _domain = std::move(object);
    return *this;
  }

  transaction::Transaction build() {
    const auto unsetMembers = enumerateUnsetMembers();
    if (not unsetMembers.empty()) {
      throw exception::transaction::UnsetBuildArgmentsException(
          "Add<object::Domain>", unsetMembers);
    }
    auto xx = transaction::Transaction(_sender, command::Add(_domain));
    xx.command.AsAdd();
    std::cout << "okokok\n";
    xx.command.AsAdd()->object;
    std::cout << "okokok\n";
    xx.command.AsAdd()->object.type<<std::endl;
    std::cout << "ffffffffffffff\n";
    xx.command.AsAdd()->object.AsDomain();
    std::cout << "kkkkkkkkkkk\n";
    std::cout << xx.command.AsAdd()->object.AsDomain()->name << std::endl;
    return xx;
  }

 private:
  std::string enumerateUnsetMembers() {
    std::string ret;
    if (not _isSetSender) ret += std::string(" ") + "sender";
    if (not _isSetDomain) ret += std::string(" ") + "Domain";
    return ret;
  }

  std::string _sender;
  object::Domain _domain;

  bool _isSetSender = false;
  bool _isSetDomain = false;
};
}

#endif