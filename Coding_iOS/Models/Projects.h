//
//  Projects.h
//  Coding_iOS
//
//  Created by 王 原闯 on 14-8-1.
//  Copyright (c) 2014年 Coding. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "User.h"
#import "Task.h"
#import "File.h"
#import "Commit.h"
#import "ProjectTopic.h"
#import "QcTask.h"
#import "HtmlMedia.h"
#import "Depot.h"
#import "ListGroupItem.h"
#import "TaskComment.h"
#import "ProjectActivities.h"




typedef NS_ENUM(NSInteger, ProjectsType)
{
    ProjectsTypeAll = 0,
    ProjectsTypeJoined,
    ProjectsTypeCreated,
    ProjectsTypeTaProject,
    ProjectsTypeTaStared
};

@interface Projects : NSObject
@property (strong, nonatomic) User *curUser;
@property (assign, nonatomic) ProjectsType type;
//请求
@property (readwrite, nonatomic, strong) NSNumber *page, *pageSize;
@property (assign, nonatomic) BOOL canLoadMore, willLoadMore, isLoading;
//解析
@property (readwrite, nonatomic, strong) NSNumber *totalPage, *totalRow;
@property (readwrite, nonatomic, strong) NSMutableArray *list;
@property (readwrite, nonatomic, strong) NSDictionary *propertyArrayMap;

+ (Projects *)projectsWithType:(ProjectsType)type andUser:(User *)user;
- (NSDictionary *)toParams;
- (NSString *)toPath;
- (void)configWithProjects:(Projects *)responsePros;

@end

@interface Project : NSObject
@property (readwrite, nonatomic, strong) NSString *icon, *name, *owner_user_name, *backend_project_path, *full_name, *description_mine, *path, *parent_depot_path;
@property (readwrite, nonatomic, strong) NSNumber *id, *owner_id, *is_public, *un_read_activities_count, *done, *processing, *star_count, *stared, *watch_count, *watched, *fork_count, *forked, *recommended;
@property (assign, nonatomic) BOOL isStaring, isWatching, isLoadingMember, isLoadingDetail;

@property (strong, nonatomic) NSString *readMeHtml;
@property (assign, nonatomic) CGFloat readMeHeight;

+ (Project *)project_All;
+ (Project *)project_FeedBack;

- (NSString *)toMembersPath;
- (NSDictionary *)toMembersParams;

- (NSString *)toUpdateVisitPath;
- (NSString *)toDetailPath;

- (NSString *)localMembersPath;

- (NSString *)toBranchOrTagPath:(NSString *)path;
@end




