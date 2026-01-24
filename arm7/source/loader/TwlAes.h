#pragma once
#include <libtwl/aes/aes.h>
#include "ndsHeader.h"

/// @brief Class handling AES crypto for DSi roms.
class TwlAes
{
public:
    /// @brief Sets up AES for the DSi rom with the given \p romHeader.
    /// @param romHeader The header of the DSi rom to setup AES for.
    /// @param key0 The 128-bit AES key to set to key slot 0.
    void SetupAes(const nds_header_twl_t* romHeader, const aes_u128_t* key0) const;

    /// @brief Performs modcrypt decryption.
    /// @param data The data to decrypt.
    /// @param length The length of the data to decrypt.
    /// @param iv The AES initialization vector.
    void DecryptModuleAes(void* data, u32 length, const aes_u128_t* iv) const;

private:
    void SetupModuleKeyXY(const nds_header_twl_t* romHeader) const;
    void SetupNandKeyX() const;
};
