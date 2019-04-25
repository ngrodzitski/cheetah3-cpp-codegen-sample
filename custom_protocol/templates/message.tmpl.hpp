//#attr $generated_at = time.strftime("%a, %d %b %Y %T GMT", time.gmtime())
// Sample protocol
// -----------------------------------------------------------------------------
// GENERATED CODE, DO NOT MODIFY
// Date:              ${generated_at}
// Template sha256:   ${template_hash}
// Parameters sha256: ${parameters_hash}

// clang-format off

#pragma once

#include <cstdint>
#include <cstring>
#include <cassert>
#include <string_view>

namespace custom_protocol
{

//
// ${class_name}_reader_t
//

//! Reader for ${class_name}.
class ${class_name}_reader_t
{
public:
    static constexpr std::size_t minimal_size_in_bytes = ${minimal_size_in_bytes};

    ${class_name}_reader_t( const void * ptr, std::size_t size_in_bytes )
        : m_ptr{ ptr }
    {
        assert( minimal_size_in_bytes <= size_in_bytes );
    }

    template < typename Data_Sizeable >
    ${class_name}_reader_t( const Data_Sizeable & raw_data )
        : ${class_name}_reader_t{ raw_data.data(), raw_data.size() }
    {
    }

    //
    // Fields.
    //

    //#for $field in $fields
    ${field.type} ${field.name}() const noexcept
    {
        ${field.type} result;
        const char * source =
            static_cast<const char *>( m_ptr ) + ${field.offset};
        std::memcpy( &result, source, sizeof(${field.type}) );
        return result;
    }

    //#end for
private:
    const void * const m_ptr;
};

//
// ${class_name}_writer_t
//

//! Writer for ${class_name}.
class ${class_name}_writer_t
{
public:
    static constexpr std::size_t minimal_size_in_bytes = ${minimal_size_in_bytes};

    ${class_name}_writer_t( void * ptr, std::size_t size_in_bytes )
        : m_ptr{ ptr }
    {
        assert( minimal_size_in_bytes <= size_in_bytes );
    }

    template < typename Data_Sizeable >
    ${class_name}_writer_t( Data_Sizeable & raw_data )
        : ${class_name}_writer_t{ raw_data.data(), raw_data.size() }
    {
    }

    //
    // Fields.
    //

    //#for $field in $fields
    ${field.type} ${field.name}() const noexcept
    {
        ${field.type} result;
        const char * source =
            static_cast<const char *>( m_ptr ) + ${field.offset};
        std::memcpy( &result, source, sizeof(${field.type}) );
        return result;
    }

    void ${field.name}( ${field.type} value ) noexcept
    {
        char * dest =
            static_cast< char * >( m_ptr ) + ${field.offset};
        std::memcpy( dest, &value, sizeof(${field.type}) );
    }

    //#end for
private:
    void * const m_ptr;
};

} // namespace custom_protocol
