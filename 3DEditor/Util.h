#pragma once

class Util final {
public:
	Util() = delete;
	~Util() = default;

public:
	static const glm::mat4 IDENTITY_MATRIX;

public:
	static float repeat(float val, float _min, float _max);
	static glm::vec3 repeat(glm::vec3 val, float _min, float _max);
	static glm::vec2 repeat(glm::vec2 val, float _min, float _max);

	static glm::vec4 generateRGBAColorById(uint32_t colorId);

	static void makeListUniqueVec3(std::vector<glm::vec3>* vectors);

	static std::string getTextFromFile(const std::filesystem::path& filePath);
};
