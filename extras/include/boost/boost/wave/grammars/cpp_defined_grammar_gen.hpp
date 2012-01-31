/*=============================================================================
    Boost.Wave: A Standard compliant C++ preprocessor library

    http://www.boost.org/

    Copyright (c) 2001-2005 Hartmut Kaiser. Distributed under the Boost
    Software License, Version 1.0. (See accompanying file
    LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(CPP_DEFINED_GRAMMAR_GEN_HPP_825BE9F5_98A3_400D_A97C_AD76B3B08632_INCLUDED)
#define CPP_DEFINED_GRAMMAR_GEN_HPP_825BE9F5_98A3_400D_A97C_AD76B3B08632_INCLUDED

#include <list>

#include <boost/spirit/core/parser.hpp>
#include <boost/pool/pool_alloc.hpp>

#include <boost/wave/util/unput_queue_iterator.hpp>

///////////////////////////////////////////////////////////////////////////////
namespace boost {
namespace wave {
namespace grammars {

template <typename LexIteratorT>
struct defined_grammar_gen
{
    typedef typename LexIteratorT::token_type token_type;
    typedef std::list<token_type, boost::fast_pool_allocator<token_type> >
        token_sequence_type;

//  The parse_operator_define function is instantiated manually twice to
//  simplify the explicit specialization of this template. This way the user
//  has only to specify one template parameter (the lexer iterator type) to
//  correctly formulate the required explicit specialization.
//  This results in no code overhead, because otherwise the function would be
//  generated by the compiler twice anyway.

    typedef boost::wave::util::unput_queue_iterator<
            typename token_sequence_type::iterator, token_type, token_sequence_type>
        iterator1_t;

    typedef boost::wave::util::unput_queue_iterator<
            LexIteratorT, token_type, token_sequence_type>
        iterator2_t;

//  parse the operator defined and return the found qualified name
    static boost::spirit::parse_info<iterator1_t>
    parse_operator_defined (iterator1_t const &first, iterator1_t const &last,
        token_sequence_type &found_qualified_name);

    static boost::spirit::parse_info<iterator2_t>
    parse_operator_defined (iterator2_t const &first, iterator2_t const &last,
        token_sequence_type &found_qualified_name);
};

///////////////////////////////////////////////////////////////////////////////
}   // namespace grammars
}   // namespace wave
}   // namespace boost

#endif // !defined(CPP_DEFINED_GRAMMAR_GEN_HPP_825BE9F5_98A3_400D_A97C_AD76B3B08632_INCLUDED)
