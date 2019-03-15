#pragma once

class Util final {
public:
	Util() = delete;
	~Util() = default;

public:
	static const glm::mat4 IDENTITY_MATRIX;
	static const std::string SHADER_DIRECTORY;

public:
	static float repeat(float val, float _min, float _max);

	static std::string getTextFromFile(const std::filesystem::path& filePath);

};
