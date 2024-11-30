/*
  SDL2 vscode 템플릿 (C++23)

  SDL2 를 사용하고 싶을때, 복붙해서 사용하세요.
*/

// C++ 표준 라이브러리
#include <print>  // std::print
// SDL2
#include "SDL2/SDL.h"

// Window 크기
constexpr int screen_width = 800;
constexpr int screen_height = 600;

int main(int argc, char* argv[]) 
{
  // Window 
  SDL_Window* window = nullptr;
  // Renderer
	SDL_Renderer* renderer = nullptr;

	// SDL 초기화
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::print("SDL2 초기화에 실패했습니다. SDL_Error: {0}\n", SDL_GetError());
    return -1;
	} 

  // Window 생성
  window = SDL_CreateWindow( "Hello SDL2!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                              screen_width, screen_height, SDL_WINDOW_SHOWN);
  if(window == nullptr) {
    std::print("Window 생성에 실패했습니다. SDL_Error: {0}\n", SDL_GetError());
    return -1;
  } 

  // Renderer 생성
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) {
    std::print("Renderer 생성에 실패했습니다. SDL_Error: {0}\n", SDL_GetError());
  }

  // Renderer 의 컬러를 설정
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  
  // 이벤트 핸들러, 메인 루프
  SDL_Event event; 
  bool quit = false; 
  // 키 입력
  const uint8_t* current_key_states = SDL_GetKeyboardState(nullptr);

  while(!quit) { 
    while(SDL_PollEvent(&event)) { 
      // 창 닫기 또는 ESC 키 입력 시 루프 종료
      if (event.type == SDL_QUIT || current_key_states[SDL_SCANCODE_ESCAPE]) 
        quit = true;
    } 
    
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    // Renderer 에 그리는 컬러로 지웁니다.
    SDL_RenderClear(renderer);
    
    // Renderer 업데이트
    SDL_RenderPresent(renderer);
  }
		
	current_key_states = nullptr;
  
  // Window, renderer 삭제
  SDL_DestroyRenderer(renderer);
  renderer = nullptr;
  SDL_DestroyWindow(window);
  window = nullptr;

	// SDL 종료
	SDL_Quit();

	return 0;
}
